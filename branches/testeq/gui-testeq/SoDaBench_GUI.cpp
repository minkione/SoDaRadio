///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SoDaBench_GUI.h"

///////////////////////////////////////////////////////////////////////////
using namespace SoDaBench_GUI;

SoDaBenchFrame::SoDaBenchFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar1 = new wxMenuBar( 0 );
	FileMenu = new wxMenu();
	wxMenuItem* OpenConfig;
	OpenConfig = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Load Configuration...") ) , wxEmptyString, wxITEM_NORMAL );
	FileMenu->Append( OpenConfig );
	
	wxMenuItem* SaveConfig;
	SaveConfig = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Save Configuration") ) , wxEmptyString, wxITEM_NORMAL );
	FileMenu->Append( SaveConfig );
	
	wxMenuItem* SaveConfigAs;
	SaveConfigAs = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Save Configuration As...") ) , wxEmptyString, wxITEM_NORMAL );
	FileMenu->Append( SaveConfigAs );
	
	wxMenuItem* Quit;
	Quit = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Quit") ) , wxEmptyString, wxITEM_NORMAL );
	FileMenu->Append( Quit );
	
	m_menubar1->Append( FileMenu, wxT("&File") );
	
	HelpMenu = new wxMenu();
	wxMenuItem* Aboutitem;
	Aboutitem = new wxMenuItem( HelpMenu, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	HelpMenu->Append( Aboutitem );
	
	wxMenuItem* UserGuideitem;
	UserGuideitem = new wxMenuItem( HelpMenu, wxID_ANY, wxString( wxT("User's Guide") ) , wxEmptyString, wxITEM_NORMAL );
	HelpMenu->Append( UserGuideitem );
	
	m_menubar1->Append( HelpMenu, wxT("Help") );
	
	this->SetMenuBar( m_menubar1 );
	
	wxBoxSizer* TopSizer;
	TopSizer = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sSpectSizer;
	sSpectSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	m_staticText91 = new wxStaticText( this, wxID_ANY, wxT("Spectrum Analyzer"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText91->Wrap( -1 );
	m_staticText91->SetFont( wxFont( 14, 70, 90, 92, false, wxEmptyString ) );
	m_staticText91->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DDKSHADOW ) );
	m_staticText91->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	sSpectSizer->Add( m_staticText91, 0, wxALL, 5 );
	
	wxGridBagSizer* gbSizer21;
	gbSizer21 = new wxGridBagSizer( 0, 0 );
	gbSizer21->SetFlexibleDirection( wxBOTH );
	gbSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sFreqCentSizer1;
	sFreqCentSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Center Frequency") ), wxHORIZONTAL );
	
	m_CenterFreqBox1 = new wxTextCtrl( this, wxID_ANY, wxT("150.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_CenterFreqBox1->SetMinSize( wxSize( 100,-1 ) );
	
	sFreqCentSizer1->Add( m_CenterFreqBox1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_CentUnitsChoices[] = { wxT("kHz"), wxT("MHz"), wxT("GHz") };
	int m_CentUnitsNChoices = sizeof( m_CentUnitsChoices ) / sizeof( wxString );
	m_CentUnits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_CentUnitsNChoices, m_CentUnitsChoices, 0 );
	m_CentUnits->SetSelection( 1 );
	sFreqCentSizer1->Add( m_CentUnits, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	gbSizer21->Add( sFreqCentSizer1, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* sFreqSpanSizer1;
	sFreqSpanSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Frequency Span") ), wxHORIZONTAL );
	
	wxString m_SpanSelectionChoices[] = { wxT("1 kHz"), wxT("2 kHz"), wxT("5 kHz"), wxT("10 kHz"), wxT("20 kHz"), wxT("50 kHz"), wxT("100 kHz"), wxT("200 kHz"), wxT("500 kHz"), wxT("1 MHz"), wxT("2 MHz"), wxT("5 MHz"), wxT("10 MHz"), wxT("20 MHz"), wxT("50 MHz"), wxT("100 MHz"), wxT("200 MHz"), wxT("500 MHz") };
	int m_SpanSelectionNChoices = sizeof( m_SpanSelectionChoices ) / sizeof( wxString );
	m_SpanSelection = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_SpanSelectionNChoices, m_SpanSelectionChoices, 0 );
	m_SpanSelection->SetSelection( 0 );
	sFreqSpanSizer1->Add( m_SpanSelection, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	gbSizer21->Add( sFreqSpanSizer1, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	wxString m_DispModeChoices[] = { wxT("Waterfall"), wxT("Spectrogram"), wxT("Off") };
	int m_DispModeNChoices = sizeof( m_DispModeChoices ) / sizeof( wxString );
	m_DispMode = new wxRadioBox( this, wxID_ANY, wxT("Mode"), wxDefaultPosition, wxDefaultSize, m_DispModeNChoices, m_DispModeChoices, 1, wxRA_SPECIFY_COLS );
	m_DispMode->SetSelection( 2 );
	bSizer31->Add( m_DispMode, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer31;
	sbSizer31 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Resolution BW") ), wxVERTICAL );
	
	wxString m_ResBWChChoices[] = { wxT("1Hz"), wxT("10Hz"), wxT("100Hz"), wxT("1kHz"), wxT("10kHz"), wxT("100kHz") };
	int m_ResBWChNChoices = sizeof( m_ResBWChChoices ) / sizeof( wxString );
	m_ResBWCh = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_ResBWChNChoices, m_ResBWChChoices, 0 );
	m_ResBWCh->SetSelection( 2 );
	sbSizer31->Add( m_ResBWCh, 0, wxALL, 5 );
	
	bSizer31->Add( sbSizer31, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer311;
	sbSizer311 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Video BW") ), wxVERTICAL );
	
	wxString m_VidBWChChoices[] = { wxT("10Hz"), wxT("100Hz"), wxT("1kHz"), wxT("10kHz"), wxT("Off") };
	int m_VidBWChNChoices = sizeof( m_VidBWChChoices ) / sizeof( wxString );
	m_VidBWCh = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_VidBWChNChoices, m_VidBWChChoices, 0 );
	m_VidBWCh->SetSelection( 4 );
	sbSizer311->Add( m_VidBWCh, 0, wxALL, 5 );
	
	bSizer31->Add( sbSizer311, 1, wxEXPAND, 5 );
	
	gbSizer21->Add( bSizer31, wxGBPosition( 2, 0 ), wxGBSpan( 3, 1 ), wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer19;
	sbSizer19 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Ref Level") ), wxHORIZONTAL );
	
	m_RefLevelBox = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -150, 20, 0 );
	sbSizer19->Add( m_RefLevelBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_choice15Choices[] = { wxT("dBm"), wxT("dBV") };
	int m_choice15NChoices = sizeof( m_choice15Choices ) / sizeof( wxString );
	m_choice15 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice15NChoices, m_choice15Choices, 0 );
	m_choice15->SetSelection( 0 );
	sbSizer19->Add( m_choice15, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer9->Add( sbSizer19, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer20;
	sbSizer20 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Vertical Resolution") ), wxHORIZONTAL );
	
	wxString m_VertResChoices[] = { wxT("1"), wxT("2"), wxT("5"), wxT("10") };
	int m_VertResNChoices = sizeof( m_VertResChoices ) / sizeof( wxString );
	m_VertRes = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_VertResNChoices, m_VertResChoices, 0 );
	m_VertRes->SetSelection( 3 );
	sbSizer20->Add( m_VertRes, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_VertResUnits = new wxStaticText( this, wxID_ANY, wxT("dBm / division"), wxDefaultPosition, wxDefaultSize, 0 );
	m_VertResUnits->Wrap( -1 );
	sbSizer20->Add( m_VertResUnits, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	bSizer9->Add( sbSizer20, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer191;
	sbSizer191 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Input Selector") ), wxVERTICAL );
	
	wxString m_AntSelChChoices[] = { wxT("TX/RX"), wxT("RX2") };
	int m_AntSelChNChoices = sizeof( m_AntSelChChoices ) / sizeof( wxString );
	m_AntSelCh = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_AntSelChNChoices, m_AntSelChChoices, 0 );
	m_AntSelCh->SetSelection( 0 );
	sbSizer191->Add( m_AntSelCh, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer9->Add( sbSizer191, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer201;
	sbSizer201 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Input Attenuation") ), wxHORIZONTAL );
	
	m_inputAtten = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 80, 0 );
	sbSizer201->Add( m_inputAtten, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_VertResUnits1 = new wxStaticText( this, wxID_ANY, wxT("dBm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_VertResUnits1->Wrap( -1 );
	sbSizer201->Add( m_VertResUnits1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer9->Add( sbSizer201, 1, wxEXPAND, 5 );
	
	gbSizer21->Add( bSizer9, wxGBPosition( 2, 1 ), wxGBSpan( 3, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer22;
	sbSizer22 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Trace Selection") ), wxHORIZONTAL );
	
	m_checkMaxTrace = new wxCheckBox( this, wxID_ANY, wxT("Trace Max"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( m_checkMaxTrace, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_checkAvgTrace = new wxCheckBox( this, wxID_ANY, wxT("Average Trace"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( m_checkAvgTrace, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	sbSizer22->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_btnTraceReset = new wxToggleButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( m_btnTraceReset, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	gbSizer21->Add( sbSizer22, wxGBPosition( 5, 0 ), wxGBSpan( 1, 2 ), wxEXPAND, 5 );
	
	m_DisplayPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 700,-1 ), wxTAB_TRAVERSAL );
	gbSizer21->Add( m_DisplayPanel, wxGBPosition( 0, 2 ), wxGBSpan( 6, 1 ), wxEXPAND | wxALL, 5 );
	
	sSpectSizer->Add( gbSizer21, 1, wxEXPAND, 5 );
	
	TopSizer->Add( sSpectSizer, 10, wxEXPAND, 5 );
	
	
	TopSizer->Add( 0, 0, 1, 0, 5 );
	
	wxStaticBoxSizer* sGenSizer;
	sGenSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxEmptyString ), wxVERTICAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Frequency Synthesizer / Sweep Generator"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetFont( wxFont( 14, 70, 90, 92, false, wxEmptyString ) );
	m_staticText9->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DDKSHADOW ) );
	m_staticText9->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	sGenSizer->Add( m_staticText9, 0, wxALL, 5 );
	
	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 0, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSwitchSizer;
	bSwitchSizer = new wxBoxSizer( wxVERTICAL );
	
	wxString m_SweepModeChoices[] = { wxT("Sweep"), wxT("Constant") };
	int m_SweepModeNChoices = sizeof( m_SweepModeChoices ) / sizeof( wxString );
	m_SweepMode = new wxRadioBox( this, wxID_ANY, wxT("Mode"), wxDefaultPosition, wxDefaultSize, m_SweepModeNChoices, m_SweepModeChoices, 2, wxRA_SPECIFY_ROWS );
	m_SweepMode->SetSelection( 0 );
	bSwitchSizer->Add( m_SweepMode, 2, wxALL, 5 );
	
	wxString m_ModulationChoices[] = { wxT("CW"), wxT("1kHz AM") };
	int m_ModulationNChoices = sizeof( m_ModulationChoices ) / sizeof( wxString );
	m_Modulation = new wxRadioBox( this, wxID_ANY, wxT("Modulation"), wxDefaultPosition, wxDefaultSize, m_ModulationNChoices, m_ModulationChoices, 2, wxRA_SPECIFY_ROWS );
	m_Modulation->SetSelection( 0 );
	bSwitchSizer->Add( m_Modulation, 2, wxALL, 5 );
	
	wxString m_RefSelChoices[] = { wxT("Internal"), wxT("External") };
	int m_RefSelNChoices = sizeof( m_RefSelChoices ) / sizeof( wxString );
	m_RefSel = new wxRadioBox( this, wxID_ANY, wxT("Ref. Freq."), wxDefaultPosition, wxDefaultSize, m_RefSelNChoices, m_RefSelChoices, 1, wxRA_SPECIFY_COLS );
	m_RefSel->SetSelection( 0 );
	bSwitchSizer->Add( m_RefSel, 2, wxALL, 5 );
	
	gbSizer2->Add( bSwitchSizer, wxGBPosition( 0, 5 ), wxGBSpan( 4, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* sFreqStartSizer;
	sFreqStartSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Start Frequency") ), wxHORIZONTAL );
	
	m_StartFreqBox = new wxTextCtrl( this, wxID_ANY, wxT("100.0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB );
	m_StartFreqBox->SetMinSize( wxSize( 100,-1 ) );
	
	sFreqStartSizer->Add( m_StartFreqBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_StartUnitsChoices[] = { wxT("kHz"), wxT("MHz"), wxT("GHz") };
	int m_StartUnitsNChoices = sizeof( m_StartUnitsChoices ) / sizeof( wxString );
	m_StartUnits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_StartUnitsNChoices, m_StartUnitsChoices, 0 );
	m_StartUnits->SetSelection( 1 );
	sFreqStartSizer->Add( m_StartUnits, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	gbSizer2->Add( sFreqStartSizer, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* sFreqStopSizer;
	sFreqStopSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Stop Frequency") ), wxHORIZONTAL );
	
	m_StopFreqBox = new wxTextCtrl( this, wxID_ANY, wxT("200.0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB );
	m_StopFreqBox->SetMinSize( wxSize( 100,-1 ) );
	
	sFreqStopSizer->Add( m_StopFreqBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_StopUnitsChoices[] = { wxT("kHz"), wxT("MHz"), wxT("GHz") };
	int m_StopUnitsNChoices = sizeof( m_StopUnitsChoices ) / sizeof( wxString );
	m_StopUnits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_StopUnitsNChoices, m_StopUnitsChoices, 0 );
	m_StopUnits->SetSelection( 1 );
	sFreqStopSizer->Add( m_StopUnits, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	gbSizer2->Add( sFreqStopSizer, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* sSweepSpeed;
	sSweepSpeed = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Sweep Speed") ), wxVERTICAL );
	
	wxString m_SweepRateChoices[] = { wxT("1 mS"), wxT("10 mS"), wxT("100 mS"), wxT("1 S"), wxT("10 S"), wxT("100 S") };
	int m_SweepRateNChoices = sizeof( m_SweepRateChoices ) / sizeof( wxString );
	m_SweepRate = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_SweepRateNChoices, m_SweepRateChoices, 0 );
	m_SweepRate->SetSelection( 4 );
	sSweepSpeed->Add( m_SweepRate, 0, wxALIGN_CENTER_VERTICAL|wxALL, 8 );
	
	gbSizer2->Add( sSweepSpeed, wxGBPosition( 2, 4 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* sSweepStep;
	sSweepStep = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Frequency Step") ), wxVERTICAL );
	
	wxString m_SweepStepChoices[] = { wxT("10 Hz"), wxT("100 Hz"), wxT("1 kHz"), wxT("10 kHz"), wxT("100 kHz"), wxT("1 MHz"), wxT("10 MHz") };
	int m_SweepStepNChoices = sizeof( m_SweepStepChoices ) / sizeof( wxString );
	m_SweepStep = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_SweepStepNChoices, m_SweepStepChoices, 0 );
	m_SweepStep->SetSelection( 4 );
	sSweepStep->Add( m_SweepStep, 0, wxALIGN_CENTER_VERTICAL|wxALL, 8 );
	
	gbSizer2->Add( sSweepStep, wxGBPosition( 1, 4 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbCurFreqSizer;
	sbCurFreqSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Current Output Frequency") ), wxHORIZONTAL );
	
	m_CurFreqDisp = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_CurFreqDisp->SetFont( wxFont( 24, 70, 90, 90, false, wxEmptyString ) );
	m_CurFreqDisp->SetMinSize( wxSize( 300,-1 ) );
	
	sbCurFreqSizer->Add( m_CurFreqDisp, 0, wxALL, 5 );
	
	wxString m_DispUnitsChoices[] = { wxT("kHz"), wxT("MHz"), wxT("GHz") };
	int m_DispUnitsNChoices = sizeof( m_DispUnitsChoices ) / sizeof( wxString );
	m_DispUnits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_DispUnitsNChoices, m_DispUnitsChoices, 0 );
	m_DispUnits->SetSelection( 0 );
	sbCurFreqSizer->Add( m_DispUnits, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	gbSizer2->Add( sbCurFreqSizer, wxGBPosition( 0, 0 ), wxGBSpan( 1, 2 ), wxALIGN_RIGHT|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sFreqCentSizer;
	sFreqCentSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Center Frequency") ), wxHORIZONTAL );
	
	m_CenterFreqBox = new wxTextCtrl( this, wxID_ANY, wxT("150.0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB );
	m_CenterFreqBox->SetMinSize( wxSize( 100,-1 ) );
	
	sFreqCentSizer->Add( m_CenterFreqBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_CenterUnitsChoices[] = { wxT("kHz"), wxT("MHz"), wxT("GHz") };
	int m_CenterUnitsNChoices = sizeof( m_CenterUnitsChoices ) / sizeof( wxString );
	m_CenterUnits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_CenterUnitsNChoices, m_CenterUnitsChoices, 0 );
	m_CenterUnits->SetSelection( 1 );
	sFreqCentSizer->Add( m_CenterUnits, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	gbSizer2->Add( sFreqCentSizer, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* sFreqSpanSizer;
	sFreqSpanSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Frequency Span") ), wxHORIZONTAL );
	
	m_SpanFreqBox = new wxTextCtrl( this, wxID_ANY, wxT("100.0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB );
	m_SpanFreqBox->SetMinSize( wxSize( 100,-1 ) );
	
	sFreqSpanSizer->Add( m_SpanFreqBox, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString m_SpanUnitsChoices[] = { wxT("kHz"), wxT("MHz"), wxT("GHz") };
	int m_SpanUnitsNChoices = sizeof( m_SpanUnitsChoices ) / sizeof( wxString );
	m_SpanUnits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_SpanUnitsNChoices, m_SpanUnitsChoices, 0 );
	m_SpanUnits->SetSelection( 1 );
	sFreqSpanSizer->Add( m_SpanUnits, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	gbSizer2->Add( sFreqSpanSizer, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbOutputPowerSizerA;
	sbOutputPowerSizerA = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Output A Power (dBm)") ), wxHORIZONTAL );
	
	m_OutPowerSliderA = new wxSlider( this, wxID_ANY, 10, -30, 20, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_BOTH|wxSL_HORIZONTAL|wxSL_LABELS );
	m_OutPowerSliderA->SetMinSize( wxSize( 200,-1 ) );
	
	sbOutputPowerSizerA->Add( m_OutPowerSliderA, 0, wxALL, 5 );
	
	gbSizer2->Add( sbOutputPowerSizerA, wxGBPosition( 0, 6 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxBoxSizer* sRFOutA;
	sRFOutA = new wxBoxSizer( wxVERTICAL );
	
	wxString m_RFOutEna_AChoices[] = { wxT("ON"), wxT("OFF") };
	int m_RFOutEna_ANChoices = sizeof( m_RFOutEna_AChoices ) / sizeof( wxString );
	m_RFOutEna_A = new wxRadioBox( this, wxID_ANY, wxT("RF Output A"), wxDefaultPosition, wxDefaultSize, m_RFOutEna_ANChoices, m_RFOutEna_AChoices, 1, wxRA_SPECIFY_COLS );
	m_RFOutEna_A->SetSelection( 1 );
	sRFOutA->Add( m_RFOutEna_A, 2, wxALL, 5 );
	
	gbSizer2->Add( sRFOutA, wxGBPosition( 0, 7 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbOutputPowerSizerB;
	sbOutputPowerSizerB = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Output B Power (dBm)") ), wxHORIZONTAL );
	
	m_OutPowerSliderB = new wxSlider( this, wxID_ANY, 10, -30, 20, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_BOTH|wxSL_HORIZONTAL|wxSL_LABELS );
	m_OutPowerSliderB->SetMinSize( wxSize( 200,-1 ) );
	
	sbOutputPowerSizerB->Add( m_OutPowerSliderB, 0, wxALL, 5 );
	
	gbSizer2->Add( sbOutputPowerSizerB, wxGBPosition( 1, 6 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxBoxSizer* sRFOutB;
	sRFOutB = new wxBoxSizer( wxVERTICAL );
	
	wxString m_RFOutEna_BChoices[] = { wxT("ON"), wxT("OFF") };
	int m_RFOutEna_BNChoices = sizeof( m_RFOutEna_BChoices ) / sizeof( wxString );
	m_RFOutEna_B = new wxRadioBox( this, wxID_ANY, wxT("RF Output B"), wxDefaultPosition, wxDefaultSize, m_RFOutEna_BNChoices, m_RFOutEna_BChoices, 1, wxRA_SPECIFY_COLS );
	m_RFOutEna_B->SetSelection( 1 );
	sRFOutB->Add( m_RFOutEna_B, 0, wxALL, 5 );
	
	gbSizer2->Add( sRFOutB, wxGBPosition( 1, 7 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	sGenSizer->Add( gbSizer2, 1, wxEXPAND, 5 );
	
	TopSizer->Add( sGenSizer, 7, wxEXPAND, 5 );
	
	this->SetSizer( TopSizer );
	this->Layout();
	
	// Connect Events
	this->Connect( OpenConfig->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnOpenConfig ) );
	this->Connect( SaveConfig->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnSaveConfig ) );
	this->Connect( SaveConfigAs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnSaveConfigAs ) );
	this->Connect( Quit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnQuit ) );
	this->Connect( Aboutitem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnAbout ) );
	this->Connect( UserGuideitem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnUserGuide ) );
	m_CenterFreqBox1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_CentUnits->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_SpanSelection->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_DispMode->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnDispModeSwitch ), NULL, this );
	m_ResBWCh->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnChoiceUpdate ), NULL, this );
	m_VidBWCh->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnChoiceUpdate ), NULL, this );
	m_RefLevelBox->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoDaBenchFrame::OnRefLevel ), NULL, this );
	m_VertRes->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnChoiceUpdate ), NULL, this );
	m_AntSelCh->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnChoiceUpdate ), NULL, this );
	m_inputAtten->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoDaBenchFrame::onInputAtten ), NULL, this );
	m_SweepMode->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnModeSel ), NULL, this );
	m_Modulation->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnModulationSel ), NULL, this );
	m_RefSel->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnRefSel ), NULL, this );
	m_StartFreqBox->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_StartFreqBox->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_StartUnits->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_StopFreqBox->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_StopFreqBox->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoDaBenchFrame::OnFreqSel ), NULL, this );
	m_StopFreqBox->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_StopUnits->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_SweepRate->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnSweepSel ), NULL, this );
	m_SweepStep->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnSweepSel ), NULL, this );
	m_DispUnits->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_CenterFreqBox->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_CenterFreqBox->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_CenterUnits->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_SpanFreqBox->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_SpanFreqBox->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_SpanUnits->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_OutPowerSliderA->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_RFOutEna_A->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnOutputEna ), NULL, this );
	m_OutPowerSliderB->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_RFOutEna_B->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnOutputEna ), NULL, this );
}

SoDaBenchFrame::~SoDaBenchFrame()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnOpenConfig ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnSaveConfig ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnSaveConfigAs ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnQuit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnAbout ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnUserGuide ) );
	m_CenterFreqBox1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_CentUnits->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_SpanSelection->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_DispMode->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnDispModeSwitch ), NULL, this );
	m_ResBWCh->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnChoiceUpdate ), NULL, this );
	m_VidBWCh->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnChoiceUpdate ), NULL, this );
	m_RefLevelBox->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoDaBenchFrame::OnRefLevel ), NULL, this );
	m_VertRes->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnChoiceUpdate ), NULL, this );
	m_AntSelCh->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnChoiceUpdate ), NULL, this );
	m_inputAtten->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoDaBenchFrame::onInputAtten ), NULL, this );
	m_SweepMode->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnModeSel ), NULL, this );
	m_Modulation->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnModulationSel ), NULL, this );
	m_RefSel->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnRefSel ), NULL, this );
	m_StartFreqBox->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_StartFreqBox->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_StartUnits->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_StopFreqBox->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_StopFreqBox->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoDaBenchFrame::OnFreqSel ), NULL, this );
	m_StopFreqBox->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_StopUnits->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_SweepRate->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnSweepSel ), NULL, this );
	m_SweepStep->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnSweepSel ), NULL, this );
	m_DispUnits->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_CenterFreqBox->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_CenterFreqBox->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_CenterUnits->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_SpanFreqBox->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_SpanFreqBox->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoDaBenchFrame::OnFreqEnter ), NULL, this );
	m_SpanUnits->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnFreqRangeSel ), NULL, this );
	m_OutPowerSliderA->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderA->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_RFOutEna_A->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnOutputEna ), NULL, this );
	m_OutPowerSliderB->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_OutPowerSliderB->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoDaBenchFrame::OnOutputPowerSel ), NULL, this );
	m_RFOutEna_B->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( SoDaBenchFrame::OnOutputEna ), NULL, this );
}

m_AboutDialog::m_AboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("SoDaLogo_Big.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer57->Add( m_bitmap1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("SoDa Radio Frequency Test Bench\nThe 'SoD' stands for Software Defined.\n The 'a' doesn't stand for anything.\n\n(Copyright 2014 kb1vc)\n  All rights reserved.\n\n  Redistribution and use in source and binary forms, with or without\n  modification, are permitted provided that the following conditions are\n  met:\n\n  Redistributions of source code must retain the above copyright\n  notice, this list of conditions and the following disclaimer.\n  Redistributions in binary form must reproduce the above copyright\n  notice, this list of conditions and the following disclaimer in\n  the documentation and/or other materials provided with the\n  distribution.\n\n  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS\n  \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT\n  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR\n  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT\n  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,\n  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT\n  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,\n  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY\n  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT\n  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE\n  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText15->Wrap( -1 );
	bSizer57->Add( m_staticText15, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_GUIVersion = new wxStaticText( this, wxID_ANY, wxT("GUI Version: "), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_GUIVersion->Wrap( -1 );
	bSizer57->Add( m_GUIVersion, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_SDRVersion = new wxStaticText( this, wxID_ANY, wxT("SDR Version"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_SDRVersion->Wrap( -1 );
	bSizer57->Add( m_SDRVersion, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticline5 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer57->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );
	
	m_AboutOK = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer57->Add( m_AboutOK, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	this->SetSizer( bSizer57 );
	this->Layout();
	
	// Connect Events
	m_AboutOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_AboutDialog::OnAboutOK ), NULL, this );
}

m_AboutDialog::~m_AboutDialog()
{
	// Disconnect Events
	m_AboutOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_AboutDialog::OnAboutOK ), NULL, this );
}

m_QuitDialogConfig::m_QuitDialogConfig( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("You've made some changes to the configuration.\nShould we save the changes?"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText10->Wrap( -1 );
	bSizer37->Add( m_staticText10, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );
	
	m_QuitNSave = new wxButton( this, wxID_ANY, wxT("Save Configuration"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( m_QuitNSave, 0, wxALL, 5 );
	
	
	bSizer38->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_QuitNoSave = new wxButton( this, wxID_ANY, wxT("Ignore Changes"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( m_QuitNoSave, 0, wxALL, 5 );
	
	bSizer37->Add( bSizer38, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer37 );
	this->Layout();
	bSizer37->Fit( this );
	
	// Connect Events
	m_QuitNSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_QuitDialogConfig::SaveConfigChanges ), NULL, this );
	m_QuitNoSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_QuitDialogConfig::OnIgnoreConfigChanges ), NULL, this );
}

m_QuitDialogConfig::~m_QuitDialogConfig()
{
	// Disconnect Events
	m_QuitNSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_QuitDialogConfig::SaveConfigChanges ), NULL, this );
	m_QuitNoSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_QuitDialogConfig::OnIgnoreConfigChanges ), NULL, this );
}

m_NewConfigDialog::m_NewConfigDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer58->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("SoDaBench could not find a configuration file.\nSelect \"OK\" to create a configuration file in\n${HOME}/.SoDaRadio/SoDaBench.sodabench_cfg"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText25->Wrap( -1 );
	bSizer58->Add( m_staticText25, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer58->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_StatusInfo = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_StatusInfo->Wrap( -1 );
	bSizer58->Add( m_StatusInfo, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer58->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer59->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_CreateConfigDefault = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_CreateConfigDefault, 0, wxALL, 5 );
	
	
	bSizer59->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_NoThanksCreateConfigDefault = new wxButton( this, wxID_ANY, wxT("No Thank You"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_NoThanksCreateConfigDefault, 0, wxALL, 5 );
	
	
	bSizer59->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bSizer58->Add( bSizer59, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer58 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_CreateConfigDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_NewConfigDialog::OnCreateConfigDefault ), NULL, this );
	m_NoThanksCreateConfigDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_NewConfigDialog::OnDismissCreateConfigDefault ), NULL, this );
}

m_NewConfigDialog::~m_NewConfigDialog()
{
	// Disconnect Events
	m_CreateConfigDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_NewConfigDialog::OnCreateConfigDefault ), NULL, this );
	m_NoThanksCreateConfigDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_NewConfigDialog::OnDismissCreateConfigDefault ), NULL, this );
}