//=============================================================================
// Project: Jebediah the Quadruped Robot
//
// Description: This code controls a quadruped robot with three degrees of 
//              freedom per leg.
//  
//    This version of the configuration file is set up to run on the
//    Lynxmotion Botboardduino board, which is similar to the Arduino Duemilanove.
//
//    This version of configuration file assumes that the servos will be controlled
//    by a Lynxmotion servo controller SSC-32 and the user is using a Lynxmotion 
//    PS2 to control the robot.
//
//====================================================================
#ifndef HEX_CFG_CHR3_H
#define HEX_CFG_CHR3_H

//#define DEBUG

#ifdef __AVR__
#if defined(UBRR1H)
#define SSCSerial         Serial1
#define XBeeSerial        Serial3 //Serial2
#else
#define XBeeSerial        Serial
#define DontAllowDebug
#endif
#else  // For My Pic32 Mega shield...
#define SSCSerial         Serial1
#define XBeeSerial        Serial3
#endif

#define QUADMODE            // We are building a quadruped rather than the default
                            // hexapod robot

//#define USEMULTI
//#define USEXBEE            // only allow to be defined on Megas...
#define USEPS2
//#define USECOMMANDER
//#define USESERIAL

// Do we want Debug Serial Output?
#define DBGSerial Serial

// Some configurations will not allow this so if one of them undefine it
#if (defined USEXBEE) || (defined USECOMMANDER)
#ifdef DontAllowDebug
#undef DBGSerial
#endif
#endif

#ifdef USESERIAL
#undef DBGSerial
#endif

#ifdef DBGSerial
#define OPT_TERMINAL_MONITOR  // Only allow this to be defined if we have a debug serial port
#endif

#ifdef OPT_TERMINAL_MONITOR
//#define OPT_SSC_FORWARDER  // only useful if terminal monitor is enabled
#define OPT_FIND_SERVO_OFFSETS    // Only useful if terminal monitor is enabled
#endif

//#define OPT_GPPLAYER

#define USE_SSC32
#define	cSSC_BINARYMODE	1			// Define if your SSC-32 card supports binary mode.
#define cSSC_BAUD        38400   //SSC32 BAUD rate

//-------------------------------------------------------------------- 
// [Debug options]
//#define DEBUG_IOPINS    // used to control if we are going to use IO pins for debug support

//--------------------------------------------------------------------
//[Botboarduino Pin Numbers]
#define SOUND_PIN    5        // Botboarduino JR pin number
// PS2 controller connections
#define PS2_DAT      6        
#define PS2_CMD      7
#define PS2_SEL      8
#define PS2_CLK      9
// Connections to SSC-32 servo controller
#define cSSC_OUT     10      	// Output pin for (SSC32 RX) on BotBoard (Yellow)
#define cSSC_IN      11      	// Input pin for (SSC32 TX) on BotBoard (Blue)
// Connections to NeoPiexel Ring eye
#define eye_data 3

// XBee was defined to use a hardware Serial port
#define XBEE_BAUD        38400
#define SERIAL_BAUD    38400

// Define Analog pin and minimum voltage that we will allow the servos to run
#define cVoltagePin  0      // Use our Analog pin jumper here...
#define cTurnOffVol  470     // 4.7v
#define cTurnOnVol   550     // 5.5V - optional part to say if voltage goes back up, turn it back on...

//--------------------------------------------------------------------
//[SSC32 Pin Numbers]
#define cRRCoxaPin      0   //Rear Right Horizontal
#define cRRFemurPin     1   //Rear Right Vertical
#define cRRTibiaPin     2   //Rear Right Tibia
#define cRRTarsPin      3   // Tar

#define cRFCoxaPin      8    //Front Right Horizontal
#define cRFFemurPin     9    //Front Right Vertical
#define cRFTibiaPin     10   //Front Right Tibia
#define cRFTarsPin      11   // Tar

#define cLRCoxaPin       16   //Rear Left Horizontal
#define cLRFemurPin      17   //Rear Left Vertical
#define cLRTibiaPin      18   //Rear Left Tibia
#define cLRTarsPin       19   // Tar

#define cLFCoxaPin      24   //Front Left Horizontal
#define cLFFemurPin     25   //Front Left Vertical
#define cLFTibiaPin     26   //Front Left Tibia
#define cLFTarsPin      27   // Tar

//--------------------------------------------------------------------
//[SERVO PULSE INVERSE]
#define cRRCoxaInv      0
#define cRRFemurInv     0
#define cRRTibiaInv     0
#define cRRTarsInv      0

#define cRFCoxaInv      1
#define cRFFemurInv     1
#define cRFTibiaInv     1
#define cRFTarsInv      1

#define cLRCoxaInv      1
#define cLRFemurInv     1
#define cLRTibiaInv     1
#define cLRTarsInv      1

#define cLFCoxaInv      0
#define cLFFemurInv     0
#define cLFTibiaInv     0
#define cLFTarsInv      0

//--------------------------------------------------------------------
//[MIN/MAX ANGLES]
#define cRRCoxaMin1     -650      //Mechanical limits of the Right Rear Leg
#define cRRCoxaMax1     650
#define cRRFemurMin1    -1050
#define cRRFemurMax1    750
#define cRRTibiaMin1    -420
#define cRRTibiaMax1    900
#define cRRTarsMin1     -1300	//4DOF ONLY - In theory the kinematics can reach about -160 deg
#define cRRTarsMax1	500	//4DOF ONLY - The kinematics will never exceed 23 deg though..

#define cRFCoxaMin1     -650      //Mechanical limits of the Right Front Leg
#define cRFCoxaMax1     650
#define cRFFemurMin1    -1050
#define cRFFemurMax1    750
#define cRFTibiaMin1    -420
#define cRFTibiaMax1    900
#define cRFTarsMin1     -1300	//4DOF ONLY - In theory the kinematics can reach about -160 deg
#define cRFTarsMax1	500	//4DOF ONLY - The kinematics will never exceed 23 deg though..

#define cLRCoxaMin1     -650      //Mechanical limits of the Left Rear Leg
#define cLRCoxaMax1     650
#define cLRFemurMin1    -1050
#define cLRFemurMax1    750
#define cLRTibiaMin1    -420
#define cLRTibiaMax1    900
#define cLRTarsMin1     -1300	//4DOF ONLY - In theory the kinematics can reach about -160 deg
#define cLRTarsMax1	500	//4DOF ONLY - The kinematics will never exceed 23 deg though..

#define cLFCoxaMin1     -650      //Mechanical limits of the Left Front Leg
#define cLFCoxaMax1     650
#define cLFFemurMin1    -1050
#define cLFFemurMax1    750
#define cLFTibiaMin1    -420
#define cLFTibiaMax1    900
#define cLFTarsMin1     -1300	//4DOF ONLY - In theory the kinematics can reach about -160 deg
#define cLFTarsMax1	500	//4DOF ONLY - The kinematics will never exceed 23 deg though..

//--------------------------------------------------------------------
// [LEG DIMENSIONS]
// Universal dimensions for each leg in mm
// Use these universal dimensions if each of the robot's legs has
// the same dimensions.
#define cXXCoxaLength     65    // Length from coxa servo horn to first femur servo horn
#define cXXFemurLength    103   // Length between femur servo horns
#define cXXTibiaLength    161   // Length from second femur servo horn to end of tibia
#define cXXTarsLength     85    // 4DOF only...

// Individual dimensions for each leg in mm
#define cRRCoxaLength     cXXCoxaLength	    //Right Rear leg
#define cRRFemurLength    cXXFemurLength
#define cRRTibiaLength    cXXTibiaLength
#define cRRTarsLength	  cXXTarsLength	    //4DOF ONLY

#define cRFCoxaLength     cXXCoxaLength	    //Rigth front leg
#define cRFFemurLength    cXXFemurLength
#define cRFTibiaLength    cXXTibiaLength
#define cRFTarsLength	  cXXTarsLength    //4DOF ONLY

#define cLRCoxaLength     cXXCoxaLength	    //Left Rear leg
#define cLRFemurLength    cXXFemurLength
#define cLRTibiaLength    cXXTibiaLength
#define cLRTarsLength	  cXXTarsLength    //4DOF ONLY

#define cLFCoxaLength     cXXCoxaLength	    //Left front leg
#define cLFFemurLength    cXXFemurLength
#define cLFTibiaLength    cXXTibiaLength
#define cLFTarsLength	  cXXTarsLength	    //4DOF ONLY


//--------------------------------------------------------------------
//[BODY DIMENSIONS]
// This first section defines the angle from the center of the body to each of the legs
#define cRRCoxaAngle1   -450   //Default Coxa setup angle, decimals = 1
#define cRFCoxaAngle1    450   //Default Coxa setup angle, decimals = 1
#define cLRCoxaAngle1   -450   //Default Coxa setup angle, decimals = 1
#define cLFCoxaAngle1    450   //Default Coxa setup angle, decimals = 1

// This second section defines the distances between the center of the body to each of the legs
#define cRROffsetX      -70    //Distance X from center of the body to the Right Rear coxa
#define cRROffsetZ       70    //Distance Z from center of the body to the Right Rear coxa
#define cRFOffsetX      -70    //Distance X from center of the body to the Right Front coxa
#define cRFOffsetZ      -70    //Distance Z from center of the body to the Right Front coxa
#define cLROffsetX       70    //Distance X from center of the body to the Left Rear coxa
#define cLROffsetZ       70    //Distance Z from center of the body to the Left Rear coxa
#define cLFOffsetX       70     //Distance X from center of the body to the Left Front coxa
#define cLFOffsetZ      -70    //Distance Z from center of the body to the Left Front coxa

//--------------------------------------------------------------------
//[START POSITIONS FEET]
#define cHexInitXZ	 110 
#define CHexInitXZCos60  55        // COS(60) = .5
#define CHexInitXZSin60  95    // sin(60) = .866
#define CHexInitXZ45    78        // Sin and cos(45) .7071
#define CHexInitY	60 //30

#if 1
#define cRRInitPosX     CHexInitXZ45      //Start positions of the Right Rear leg
#define cRRInitPosY     CHexInitY
#define cRRInitPosZ     CHexInitXZ45

#define cRFInitPosX     CHexInitXZ45      //Start positions of the Right Front leg
#define cRFInitPosY     CHexInitY
#define cRFInitPosZ     -CHexInitXZ45

#define cLRInitPosX     CHexInitXZ45      //Start positions of the Left Rear leg
#define cLRInitPosY     CHexInitY
#define cLRInitPosZ     CHexInitXZ45

#define cLFInitPosX     CHexInitXZ45      //Start positions of the Left Front leg
#define cLFInitPosY     CHexInitY
#define cLFInitPosZ     -CHexInitXZ45
#endif
//--------------------------------------------------------------------
//[Tars factors used in formula to calc Tarsus angle relative to the ground]
#define cTarsConst	720	//4DOF ONLY
#define cTarsMulti	2	//4DOF ONLY
#define cTarsFactorA	70	//4DOF ONLY
#define cTarsFactorB	60	//4DOF ONLY
#define cTarsFactorC	50	//4DOF ONLY

#endif CFG_HEX_H

