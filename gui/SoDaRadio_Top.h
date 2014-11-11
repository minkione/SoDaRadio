#ifndef __SoDaRadio_Top__
#define __SoDaRadio_Top__
/*
  Copyright (c) 2012, Matthew H. Reilly (kb1vc)
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:

  Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
  Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in
  the documentation and/or other materials provided with the
  distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
   @file
   Subclass of SoDaRadioFrame, which is generated by wxFormBuilder.
*/

#include "SoDaRadio_GUI.h"
#include "SoDaRadio_Band.hxx"
#include "GuiParams.hxx"
#include "TunerDigit.hxx"
#include "RadioListenerThread.hxx"
#include "../src/UDSockets.hxx"
#include "../src/Command.hxx"
#include "../src/Debug.hxx"
#include <map>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/format.hpp>
#include "xyplot.hxx"
#include "waterfall.hxx"
#include <wx/wx.h>
#include <wx/string.h>
#include <wx/wxchar.h>
#include <wx/thread.h>

namespace SoDaRadio_GUI {
  
  class TuningDialog;
  class ControlsDialog;
  class BandConfigDialog;
  class LogDialog;
  class SpectConfigDialog;

  /**
   * The SoDaRadio object
   *
   * The SoDaRadio program provides a wxWidgets based GUI to control
   * the SoDa radio SDR control program. SoDaRadio is partitioned into
   * three major components
   *
   * @li The Application object defined in SoDaRadio_App that launches the 
   * main GUI control thread defined by SoDaRadio_Top
   * @li the RadioListenener object that connects to the SoDa::UI thread.
   * @li the wxWidgets GUI event loop that dispatches user requests
   * through the SoDaRadio_Top thread.
   */
  class SoDaRadio_Top : public SoDaRadioFrame, public SoDa::Debug, public SoDa::MBoxNotify
  {
    friend class TuningDialog;
    friend class ControlsDialog;
    friend class SpectConfigDialog;
    friend class XYPlot;
    friend class Waterfall;
  protected:
    // Handlers for SoDaRadioFrame events.
    void OnOpenConfig( wxCommandEvent& event );
    void OnSaveConfig( wxCommandEvent& event );
    void OnSaveConfigAs( wxCommandEvent& event );
    void OnOpenLogfile( wxCommandEvent& event );
    void OnQuit( wxCommandEvent& event );
    void OnClose( wxCloseEvent& event );

    void OnSetFromCall( wxCommandEvent& event); 
    void OnSetFromGrid( wxCommandEvent& event); 
    void OnConfigBand( wxCommandEvent& event);
    void OnBandSelect( wxCommandEvent& event); 

    void OnQSOMenuSet( wxCommandEvent & event);
  
    void OnAbout( wxCommandEvent & event);
    void OnTunePopup ( wxCommandEvent & event);
    void OnCtrlPopup ( wxCommandEvent & event);

    void OnEditLog( wxCommandEvent & event);
    void OnLogContact( wxCommandEvent & event);
    void OnSaveComment( wxCommandEvent & event); 
  
    void OnNewToCall( wxCommandEvent & event); 
    void OnNewToGridEnter( wxCommandEvent & event); 
    void OnNewToGrid( wxCommandEvent & event); 
	
    void OnSelectPage( wxNotebookEvent& event );
    void OnWFallFreqSel( wxMouseEvent& event );
    void OnPeriodogramFreqSel( wxMouseEvent& event );
    void OnPerWindowLenUpdate(wxScrollEvent & event);
    void OnWfallWindowLenUpdate(wxScrollEvent & event);
    void OnScrollSpeedUpdate(wxScrollEvent & event);
    void OnOpenSpectConfig(wxMouseEvent & event);
    void OnMenuConfigSpect(wxCommandEvent & event);
    
    void OnTXOnOff( wxCommandEvent& event );
    void OnCWControl( wxCommandEvent& event );
    void OnClrCWBuffer( wxCommandEvent& event );
    void OnSendText( wxCommandEvent & event);

    void OnAFBWChoice( wxCommandEvent& event );
    void OnModeChoice( wxCommandEvent& event );
    void OnTXRXLock( wxCommandEvent& event );
    void OnAFGainScroll(wxScrollEvent & event); 
    void OnRFGainScroll(wxScrollEvent & event); 

    void OnPerRefLevel( wxSpinEvent& event );
    void OnPerBandSpread( wxCommandEvent& event );
    void OnPerYScaleChoice( wxCommandEvent& event );
    void OnPerCFreqStep( wxSpinEvent& event );
    void OnPerRxToCentFreq( wxCommandEvent& event );

    void UpdateCenterFreq(double cfreq); 
  
    void SetPerVals(double cfreq, double reflevel, float yscale, float bspread);

    void OnCopyTXtoRX( wxCommandEvent& event );
    void OnCopyRXtoTX( wxCommandEvent& event );

    void OnLastTX( wxCommandEvent& event );
    void OnLastRX( wxCommandEvent& event );
  
    // raising dialog boxes
    void OnConfigSpectrum( wxCommandEvent & event);

    // message handlers
    void OnUpdateSpectrumPlot(wxCommandEvent & event); 
    void OnUpdateGPSLoc(wxCommandEvent & event); 
    void OnUpdateGPSTime(wxCommandEvent & event); 
    void OnTerminateTX(wxCommandEvent & event); 
  
    // CW stuff
    void sendCWText( const wxString & cwstr, int repeat_count = 1, bool append_cr = true);
    void sendCWMarker(int marker_id); 

    void UpdateRXFreq(double freq);
    void UpdateTXFreq(double freq);

    // mailbox notification event
    void OnMailboxReady(wxCommandEvent & event);
    
    
  public:
    // mailbox notification callback
    void notify();

    double GetLOMult() { return lo_multiplier; }
    void SetLOMult(double v) { lo_multiplier = v; }
    double GetLONominalBase() { return nominal_lo_base_freq; }
    void SetLONominalBase(double v) { nominal_lo_base_freq = v; }

    void SaveCurrentBand();
    void SetCurrentBand(SoDaRadio_Band * band); 

    wxString getModeString() { return m_ModeBox->GetStringSelection(); }

    // message types. 
    enum MSG_ID { MSG_UPDATE_SPECTRUM, MSG_HANDLE_CMD, MSG_UPDATE_GPSLOC, MSG_UPDATE_GPSTIME, MSG_TERMINATE_TX, MSG_UPDATE_MODELNAME, MSG_UPDATE_ANTNAME };
    /** Constructor */
    SoDaRadio_Top( SoDa::GuiParams & parms, wxWindow* parent );
    // plot maintenance
    void UpdateAxes(); 

    void SetRXFreqFromDisp(double freq);
	
    double spectrum_center_freq;
    float spectrum_bandspread;
    float spectrum_y_scale;
    float spectrum_y_reflevel;

    double GetRXFreq() { return rx_frequency; }

    SoDa::UD::ClientSocket * GetCmdQueue() { return soda_radio; }
    SoDa::UD::ClientSocket * GetFFTQueue() { return soda_fft; }

    bool CreateSpectrumTrace(double * freqs, float * powers, unsigned int len);

    void setLOOffset(double v);
    
    double getTXOffset() {
      return tx_transverter_offset;
    }
    
    double getRXOffset() {
      return rx_transverter_offset;
    }

    void setGPSLoc(double lat, double lon);

    void setGPSTime(unsigned char h, unsigned char m, unsigned char s); 

    wxString getGPSLat() { return GPS_Lat_Str; }
    wxString getGPSLon() { return GPS_Lon_Str; }
    wxString getGPSGrid() { return GPS_Grid_Str; }
    wxString getGPSUTC() { return GPS_UTC_Str; }

    void setSDRVersion(char * buf) {
      wxMutexLocker lock(ctrl_mutex);
      strncpy(SDR_version_string, buf, 64);
    }
  
    void SaveSoDaConfig(const wxString & fname);
    bool LoadSoDaConfig(const wxString & fname);
    void CreateDefaultConfig(boost::property_tree::ptree * config_tree);
    void SetConfigFileName(const wxString & fname); 

    void setupBandSelect(SoDaRadio_BandSet * bandset);

    wxString radio_modelname;
    
    void setRadioName(const wxString & mname) {
      wxMutexLocker lock(ctrl_mutex);
      radio_modelname = wxT("SoDa Radio ") + mname; 
      wxCommandEvent event(wxEVT_COMMAND_MENU_SELECTED,
			   SoDaRadio_Top::MSG_UPDATE_MODELNAME);
      pendEvent(event); 
    }

    void OnUpdateModelName(wxCommandEvent & event) {
      this->SetTitle(radio_modelname); 
    }

    wxString rx_antenna_name;
    
    void setAntennaName(const wxString & name) {
      wxMutexLocker lock(ctrl_mutex);
      rx_antenna_name = name;
      wxCommandEvent event(wxEVT_COMMAND_MENU_SELECTED,
			   SoDaRadio_Top::MSG_UPDATE_ANTNAME);
      pendEvent(event); 
    }

    void OnUpdateAntName(wxCommandEvent & event) {
      wxString lab = wxT("RX_Ant: ") + rx_antenna_name;
      m_ClueBar->SetStatusText(lab, 2);
    }

    void pendEvent(wxCommandEvent & event) {
      GetEventHandler()->AddPendingEvent(event);
    }

    // start the listener thread
    void startListener() {
      // now launch it.
      debugMsg("Launching listener thread.");
      if(listener->Create() != wxTHREAD_NO_ERROR) {
	wxLogError(wxT("Couldn't create radio listener thread...")); 
      }

      debugMsg("Running listener thread.");
      listener->Run(); 
      
      // ask 
      SoDa::Command ncmd(SoDa::Command::GET, SoDa::Command::HWMB_REP);
      sendMsg(&ncmd);
      debugMsg("sent model ID request.\n");
    }

    // complete configuration
    void configureRadio(SoDa::GuiParams & params);

  private:
    char SDR_version_string[64];

    void updateMarkers() {
      double flo, fhi;
      flo = fhi = rx_frequency;

      double lo_off = 0.0;
      double hi_off = 0.0; 
      // what is AF bw?
      switch (audio_filter) {
      case SoDa::Command::BW_100:
	lo_off = 400.0;
	hi_off = 500.0; 
	break; 
      case SoDa::Command::BW_500:
	lo_off = 400.0;
	hi_off = 900.0; 
	break; 
      case SoDa::Command::BW_2000:
	lo_off = 300.0;
	hi_off = 2300.0; 
	break; 
      case SoDa::Command::BW_6000:
	lo_off = 300.0;
	hi_off = 6300.0; 
	break; 
      }
      
      
      // is mode low or high?
      if((modulation_type == SoDa::Command::CW_L) ||
	 (modulation_type == SoDa::Command::LSB)) {
	fhi = fhi - lo_off;
	flo = flo - hi_off; 
      }
      else if((modulation_type == SoDa::Command::CW_U) ||
	      (modulation_type == SoDa::Command::USB)) {
	fhi = fhi + hi_off;
	flo = flo + lo_off; 
      }
      else if(modulation_type == SoDa::Command::AM) {
	flo = flo - hi_off; 
	fhi = fhi + hi_off; 
      } 
      else if (modulation_type == SoDa::Command::NBFM) {
	flo = flo - 6.25e3; 
	fhi = fhi + 6.25e3; 
      }
      else if (modulation_type == SoDa::Command::WBFM) {
	flo = flo - 20e3;
	fhi = fhi + 20e3; 
      }


      wfall_plot->SetTuningMarkers(flo, fhi); 
    }

    wxString GPS_Lat_Str; // (wxT("XXX"));
    wxString GPS_Lon_Str; // (wxT("XXX"));
    wxString GPS_Grid_Str; //(wxT("XXX"));
    wxString GPS_UTC_Str; // (wxT("XXX"));
  
    unsigned int debug_mode; 
    double rx_frequency, tx_frequency;
    double last_tx_frequency, last_rx_frequency;
    bool tx_rx_locked;
    void CheckLockedTuning(bool rx_updatep);
  
    // spectrum displays
    XYPlot * pgram_plot;
    Waterfall * wfall_plot;
    // the trace
    XYPlot::Trace * pgram_trace; 

    // Control and Tuning dialogs
    TuningDialog * tuner; 
    ControlsDialog * controls;
    BandConfigDialog * bandconf; 
    LogDialog * logdialog;
    SpectConfigDialog * spect_config;
    
    // State of the radio
    bool tx_on;
    bool cw_mode;
    bool cw_upper;
    SoDa::Command::ModulationType modulation_type; 
    SoDa::Command::AudioFilterBW audio_filter;
    
    bool dead_carrier;
    wxString save_config_file_name;
    float tx_rf_outpower;

    // the antenna choice
    void setRXAnt(std::string rx_ant_sel); 

    double tx_transverter_offset, rx_transverter_offset;

    double nominal_lo_base_freq;
    double lo_multiplier;
    double actual_lo_base_freq;

    // the band list.
    SoDaRadio_BandSet * bandset; 
    SoDaRadio_Band * current_band; ///< the band that we're currently in (or NULL)

    
    double applyRXTVOffset(double fr) {
      return fr - rx_transverter_offset; 
    }
    double applyTXTVOffset(double fr) {
      return fr - tx_transverter_offset; 
    }

    // The log file
    bool OpenSoDaLog(const wxString & fname);
    wxString log_file_name;

    // who and where are we?
    wxString from_callsign;
    wxString from_grid;
    wxString to_grid;
    wxString to_callsign; 

    // Comm socket to SoDa radio server.
    SoDa::UD::ClientSocket * soda_radio, * soda_fft;
    void sendMsg(const SoDa::Command * cmd) {
      soda_radio->put(cmd, sizeof(SoDa::Command));
    }

    // sweep tuning control
    double sweep_width;
    double sweep_speed;
    double getSweepWidth() { return sweep_width; }
    void setSweepWidth(double v) { sweep_width = v; }
    double getSweepSpeed() { return sweep_speed; }
    void setSweepSpeed(double v) { sweep_speed = v; }
  
    // the listener thread
    RadioListenerThread * listener;

    // the mutex used to synchronize access between the GUI
    // thread and the radio listener thread
    wxMutex ctrl_mutex; 
  
    // helpful stuff 
    wxColour default_button_bg_color;
    void UpdateNavigation();
	
    // configuration info
    boost::property_tree::ptree * config_tree_alloc, * config_tree; 

    // Spectrum display
    double GetSpread();
    void SetSpectrum(double bandspread);
    double GetYScale();
    void SetYScale(double v);

    unsigned long last_cfreq;
    unsigned long cfreq_step; 

  };

  class AboutDialog : public m_AboutDialog {
  public:

  AboutDialog(wxWindow * parent, char * SDR_version_string) : m_AboutDialog(parent) {
      // setup the gui version string
      std::string guiv = (boost::format("GUI Version: %s SVN %s") % PACKAGE_VERSION % SVN_VERSION).str();
      wxString wxver(guiv.c_str(), wxConvUTF8);
      m_GUIVersion->SetLabel(wxver);
      std::string sdrv = (boost::format("SDR Version: %s") % SDR_version_string).str();
      wxString wxsdr(sdrv.c_str(), wxConvUTF8);
      m_SDRVersion->SetLabel(wxsdr); 
    }
    void OnAboutOK( wxCommandEvent & event); 
  
  };

  class NewConfigDialog : public m_NewConfigDialog {
  public:
  NewConfigDialog(wxWindow * parent, SoDaRadio_Top * _radio) : m_NewConfigDialog(parent) {
      radio = _radio; 
    }
    void OnCreateConfigDefault( wxCommandEvent & event);
    void OnDismissCreateConfigDefault( wxCommandEvent & event);
    SoDaRadio_Top * radio; 
  };
  
  class ControlsDialog : public m_ControlsDialog {
  public:
    ControlsDialog(wxWindow * parent, SoDaRadio_Top * radio);


    float getCWSpeed() { return m_CWSpeed->GetValue(); }
    void setCWSpeed(float s) {
      m_CWSpeed->SetValue(s);
      wxScrollEvent nullSE;
      OnCWSpeed(nullSE);
    }
  
    float getSTGain() { return m_STGain->GetValue(); }
    void setSTGain(float v) {
      m_STGain->SetValue(v);
      wxScrollEvent nullSE;
      OnSTGainScroll(nullSE);
    }
  
    void setTXPower(double v) {
      m_TXPower->SetValue(v);
      wxScrollEvent nullSE; 
      OnTXPower(nullSE); 
    }
  
    // power conversion
    float powerToTXSetting(float fpow) {
      // take power in dBm and convert to
      // settings for TX
      return (fpow);
    }
    float txSettingToPower(float setting) {
      // take power in dBm and convert to
      // settings for TX
      return setting; // ((setting - 10.0) / 0.6); 
    }

  private:
    SoDaRadio_Top * radio_top; 

    void OnSTGainScroll(wxScrollEvent & event);
    void OnCWSpeed(wxScrollEvent & event);
    void OnTXPower( wxScrollEvent & event);
    void OnCtrlDone( wxCommandEvent & event );
  };

  class TuningDialog : public m_TuningDialog {
  public:
    TuningDialog(wxWindow *parent, SoDaRadio_Top * radio);

    void newTXFreq() {
      tx[0]->newFreq();     
    }
    void newRXFreq() {
      rx[0]->newFreq();     
    }

    bool getExtRefEna() { return m_ExtRefEn->GetValue(); }
    void setExtRefEna(bool v) {
      wxCommandEvent nullCE;
      m_ExtRefEn->SetValue(v);
      OnExtRefEna(nullCE);
    }
  
  private:
    // Tuner structures. 
    std::map<wxWindow *, TunerDigit *> rx_tuner, tx_tuner;
    TunerDigit * rx[11], * tx[11];
    SoDaRadio_Top * radio_top; 

    void OnDigitUp( wxCommandEvent& event );
    void OnDigitDown( wxCommandEvent& event );
    void OnTuningDone( wxCommandEvent & event );

    void OnCopyTXtoRX( wxCommandEvent& event );
    void OnCopyRXtoTX( wxCommandEvent& event );

    void OnLastTX( wxCommandEvent& event );
    void OnLastRX( wxCommandEvent& event );

    // external reference and LO calib
    void OnExtRefEna(wxCommandEvent & event);
    void OnTransvLOCal(wxCommandEvent & event);
  };

  class LogDialog : public m_LogDialog {
  public:
  LogDialog(wxWindow * parent, SoDaRadio_Top * radio) :
    m_LogDialog(parent) {
      radio_top = radio;
      log_ena = false; 
    }
  
    void OnLogOK( wxCommandEvent & event);
    void OnLogCellChange( wxGridEvent & event); 
    void SaveContact(const wxString & time,
		     const wxString & from_call,
		     const wxString & from_grid,
		     const wxString & to_call,
		     const wxString & to_grid,
		     const wxString & mode,
		     double tx_freq,
		     double rx_freq,
		     const wxString & dist);
    void SaveComment(const wxString & comment); 

    unsigned int getNumEntries() {
      return m_LogGrid->GetNumberRows(); 
    }

    void scrollToBottom() {
      m_LogGrid->MakeCellVisible(m_LogGrid->GetNumberRows(), 1);
    }

    /// set two streams -- the log stream that gets the complete
    /// log, and the checkpoint stream that gets each entry as it
    /// is written.  (The logstream contains the edited contents.)

    void closeLog() {
      if(log_ena) {
	saveLog(); 
	logst.close();
	ckpst.close(); 
      }
    }
  
    void openLog(const std::string & basename)
    {
      closeLog();
      readLog(basename);
    
      logst.open(basename.c_str(), std::fstream::out);
      if(logst.is_open()) {
	logst << "foo" << std::endl;
      }
      else {
	std::cerr << "logst open failed on file " << basename
		  << " with failbits set to " << (hex) << logst.rdstate()
		  << std::endl; 
      }
      std::string ckpname = basename + "_ckp"; 
      ckpst.open(ckpname.c_str(), std::fstream::out | std::fstream::app);

      log_ena = true; 
    }

    void readLog(const std::string & basename); 
    void saveLog();
    void checkpointLog();
  
  private:
    SoDaRadio_Top * radio_top;
    std::fstream logst, ckpst;
    bool log_ena; 
  };

  class BandConfigDialog : public m_BandConfigDialog {
  public:
  BandConfigDialog(wxWindow * parent, SoDaRadio_Top * radio) :
    m_BandConfigDialog(parent) {
      radio_top = radio;
    }

    void OnBandOK( wxCommandEvent & event);
    void OnBandCancel( wxCommandEvent & event);
    void OnTransverterModeSel( wxCommandEvent & event);

    void OnConfigChoice( wxCommandEvent & event); 
    void OnBandActivate( wxCommandEvent & event);

    void OnProblem(std::string const & probstring); 


    /// load the configuration list with the bands we know about.
    void initBandList(SoDaRadio_BandSet * bandset);

    void clearTextBoxes() {
      m_BandName->Clear();
      m_low_edge->Clear();
      m_high_edge->Clear();
    }

    void setChoiceBox(wxChoice * box, std::string & sel);
    
  private:
    SoDaRadio_Top * radio_top;
    SoDaRadio_BandSet * bands;
  }; 


  class BandConfigProblem : public m_BandConfigProblem {
  public:

  BandConfigProblem(wxWindow * parent, const char * probstring) : m_BandConfigProblem(parent) {
      // setup the gui version string
      wxString wxver(probstring, wxConvUTF8);
      m_BandConfigReason->SetLabel(wxver);
    }
    void OnBandErrorOK( wxCommandEvent & event); 
  
  };

  class SpectConfigDialog : public m_SpectConfigDialog {
  public:
    SpectConfigDialog(wxWindow * parent, SoDaRadio_Top * radio) : m_SpectConfigDialog(parent) {
      radio_top = radio; 
    }
    void OnPerCFreqStep( wxSpinEvent& event ) {
      radio_top->OnPerCFreqStep(event);
    }

    void OnPerBandSpread(wxCommandEvent & event) {
      radio_top->OnPerBandSpread(event);
    }

    void OnPerYScaleChoice(wxCommandEvent & event) {
      radio_top->OnPerYScaleChoice(event);
    }
    
    void OnPerRefLevel(wxSpinEvent & event) {
      radio_top->OnPerRefLevel(event);
    }

    void OnWindowLenUpdate( wxScrollEvent& event ) {
      wxSlider * w = (wxSlider *) event.GetEventObject(); 
      if(w == m_PeriodogramWindowSel) radio_top->OnPerWindowLenUpdate(event);
      else radio_top->OnWfallWindowLenUpdate(event);

    }

    void OnScrollSpeedUpdate( wxScrollEvent& event ) {
      radio_top->OnScrollSpeedUpdate(event); 
    }
    
    void OnDone( wxCommandEvent& event ) { closeWindow(); }
    void OnDone(wxCloseEvent & event) { closeWindow(); }

    int getPerWindowLen() {
      return m_PeriodogramWindowSel->GetValue(); 
    }

    int getWfallWindowLen() {
      return m_WaterfallWindowSel->GetValue(); 
    }

    double setBandSpread(double bandspread) {
      double spval[] = {25, 50, 100, 200, 500, -1}; //spread in kHz
      int selidx = -1;
      int minidx = -1;
      int i;
      
      for(i = 0; spval[i] > 0; i++) {
	if(spval[i] == bandspread) selidx = i;
	if(spval[i] < bandspread) minidx = i;
      }
      
      if(selidx == -1) {
	if(minidx != -1) selidx = minidx;
	else selidx = 0; 
      }
      m_BandSpreadChoice->SetSelection(selidx);

      return spval[selidx]; 
    }
    
    double getBandSpread() {
      double spval[] = {25, 50, 100, 200, 500}; //spread in kHz
      int selidx = m_BandSpreadChoice->GetSelection();
      
      if(selidx > 4) selidx = 4;

      return 1.0e3 * spval[selidx]; 
    }

    void setFreqSpinner(double low, double high, double center)
    {
      m_cFreqSpin->SetRange(low, high);
      m_cFreqSpin->SetValue(center);
    }
    
    double setdBScale(double v) {
      double spval[] = {1, 5, 10, 20, 0}; // range in dB / box
      
      int selidx = -1;
      int minidx = -1;

      int i;
      for(i = 0; spval[i] > 0; i++) {
	if(spval[i] == v) selidx = i;
	if(spval[i] < v) minidx = i; 
      }

      if(selidx == -1) {
	if(minidx != -1) selidx = minidx;
	else selidx = 0; 
      }
      
      m_dBScale->SetSelection(selidx);
      return spval[selidx]; 
    }
    
    double getdBScale() {
      double spval[] = {1, 5, 10, 20}; // range in dB / box
      int selidx = m_dBScale->GetSelection();
      
      if(selidx > 3) selidx = 3;
      
      return spval[selidx]; 
    }

    double setRefLevel(double v) {
      m_RefLevel->SetValue(v);
      return v; 
    }
    
    double getRefLevel() {
      return m_RefLevel->GetValue();
    }
    
    void closeWindow() {
      // close the config dialog.
      if(IsModal()) {
	EndModal(wxID_OK);
      }
      else {
	SetReturnCode(wxID_OK);
	this->Show(false);
      }
    }

  private:
    SoDaRadio_Top * radio_top; 
  }; 
}
#endif // __SoDaRadio_Top__
