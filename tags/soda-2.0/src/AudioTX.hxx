/*
Copyright (c) 2012,2013,2014 Matthew H. Reilly (kb1vc)
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

#ifndef AUDIOTX_HDR
#define AUDIOTX_HDR
#include "SoDaBase.hxx"
#include "MultiMBox.hxx"
#include "Params.hxx"
#include "Command.hxx"
#include "ReSamplers625x48.hxx"
#include "HilbertTransformer.hxx"
#include "AudioIfc.hxx"

namespace SoDa {
  /**
   * AudioTX -- this is the audio processing chain for the transmit path
   *
   * @image html SoDa_Radio_TX_Signal_Path.svg
   *
   * The AudioTX unit creates I/Q audio streams for LSB, SSB, and AM modulation.
   * Frequency Modulation schemes are not yet implemented.
   * CW (CW_L and CW_U) modes are implemented in the USRPTX module and the CW unit.
   *
   */
  class AudioTX : public SoDaThread {
  public:
    /**
     * constructor
     *
     * @param params command line parameter object
     * @param tx_stream pointer to mailbox holding USRP RX bitstream
     * @param cmd_stream pointer to mailbox holding control/report commands
     * @param audio_ifc pointer to the audio output handler
     */
    AudioTX(Params * params,
	    DatMBox * tx_stream,
	    CmdMBox * cmd_stream,
	    AudioIfc * audio_ifc);
    /**
     * @brief the run method -- does the work of the audio transmitter process
     */
    void run();
  private:
    /**
     * @brief execute GET commands from the command channel
     * @param cmd the incoming command
     */
    void execGetCommand(Command * cmd); 
    /**
     * @brief handle SET commands from the command channel
     * @param cmd the incoming command
     */
    void execSetCommand(Command * cmd); 
    /**
     * @brief handle Report commands from the command channel
     * @param cmd the incoming command
     */
    void execRepCommand(Command * cmd); 

    /**
     * @brief create an AM/SSB modulation envelope
     *
     * @param audio_buf the buffer of modulating audio info
     * @param len the length of the audio buffer
     * @param is_usb if true, generate upper sideband
     * @param is_lsb if true, generate lower sideband
     * if both is_usb and is_lsb are false, the modulator
     * creates an IQ stream that is amplitude modulated
     */
    SoDa::SoDaBuf * modulateAM(float * audio_buf, unsigned int len, bool is_usb, bool is_lsb); 
    
    DatMBox * tx_stream; ///< outbound RF stream to USRPTX transmit chain
    CmdMBox * cmd_stream; ///< command stream from UI and other units
    unsigned int cmd_subs; ///< subscription ID for command stream
    
    // The interpolator
    SoDa::ReSample48to625 * interpolator;  ///< Upsample from 48KHz to 625KHz

    // parameters
    unsigned int audio_buffer_size; ///< length (in samples) of an input audio buffer
    double audio_sample_rate; ///< wired in lots of places as 48KHz
    unsigned int tx_buffer_size;  ///< how long is the outbound RF buffer

    SoDa::Command::ModulationType tx_mode; ///< what modulation scheme? USB? LSB? CW_U?...
    bool cw_tx_mode; ///< if true, tx_mode is CW_L or CW_U
    bool tx_on; ///< set by Command::TX_STATE to on or off
    

    float af_gain; ///< local microphone gain. 

    // audio server state
    AudioIfc * audio_ifc; ///< pointer to an AudioIfc object for the microphone input
    bool tx_stream_on; ///< if true, we are transmitting. 

    // we need some intermediate storage for things like
    // the IQ buffer
    std::complex<float> * audio_IQ_buf; ///< temporary storage for outbound modulation envelope

    /**
     * SSB modulation requires that we upsample before
     * doing the quadrature generation.
     */
    float * ssb_af_upsample; 

    /**
     *The hilbert transformer to create an analytic (I/Q) signal.
     */
    SoDa::HilbertTransformer * hilbert;

    /**
     * mic gain is adjustable, to make sure we aren't noxious.
     */
    float mic_gain;

    bool debug_mode; ///< if true, print extra debug info
  }; 
}


#endif