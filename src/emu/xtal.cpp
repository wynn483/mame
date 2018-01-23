// license:BSD-3-Clause
// copyright-holders:Nicola Salmoria
/*************************************************************************

    xtal.h

    Documentation and consistent naming for known existing crystals.

***************************************************************************

    PCB Crystal Reference
    ----------------------
       _____     ________
       |16 |    |o       |
       |MHZ|    |16.0MHZ |
       |___|    |________|
       |   |

    There is a finite list of _manufactured_ crystals. This file aims
    to document all of the known speeds that crystals were available in.
    Feel free to add to the list if you find another speed crystal on
    a PCB, but please DON'T GUESS!

    Remember that some very high frequencies (typically above 100MHz) are
    generated by a frequency multiplying IC from a lower frequency
    crystal.

    This is intended as a reference of existing parts to prevent incorrect
    clock speed measurements with digital frequency counters being used
    in drivers. When measuring clocks, remember that most parts have a
    tolerance so be sure to reference existing parts only and not just
    accept direct readings as 100% true.

    MAME supports fractions in crystal frequencies, but for historical
    and readability reasons we tend to write the closest integer
    value. For example, XTAL(3'579'545) should actually be
    3579545.454545...Hz (39375000/11).  This is no problem though: see
    above note about tolerance.

    In the "Examples" column, please don't add 1000 examples, this is just
    for interest, so two or three examples is enough.
    The actual reference where the xtals are used can be found in the
    driver files by searching for the frequency (e.g. "XTAL(4'915'200)")

    (Thanks to Guru for starting this documentation.)

**************************************************************************/

// This array *must* stay in order, it's binary-searched
const double XTAL::known_xtals[] = {
/*
    Frequency    Examples
    -----------  ------------------------------------------------------------ */
	     32'768, /* 32.768kHz, used to drive RTC chips */
	    384'000, /* Resonator - Commonly used for driving OKI MSM5205 */
	    400'000, /* Resonator - OKI MSM5205 on Great Swordman h/w */
	    430'000, /* Resonator */
	    455'000, /* Resonator - OKI MSM5205 on Gladiator h/w */
	    512'000, /* Resonator - Toshiba TC8830F */
	    600'000,
	    640'000, /* Resonator - NEC UPD7759, Texas Instruments Speech Chips @ 8khz */
	    960'000, /* Resonator - Xerox Notetaker Keyboard UART */
	  1'000'000, /* Used to drive OKI M6295 chips */
	  1'056'000, /* Resonator - OKI M6295 on Trio The Punch h/w */
	  1'294'400, /* BBN BitGraph PSG */
	  1'750'000, /* RCA CDP1861 */
	  1'797'100, /* SWTPC 6800 (with MIKBUG) */
	  1'843'200, /* Bondwell 12/14 */
	  1'996'800, /* NEC PC-98xx */
	  2'000'000,
	  2'012'160, /* Cidelsa Draco sound board */
	  2'097'152, /* Icatel 1995 - Brazilian public payphone */
	  2'457'600, /* Atari ST MFP, NEC PC-98xx */
	  2'500'000, /* Janken Man units */
	  2'950'000, /* Playmatic MPU-C, MPU-III & Sound-3 */
	  3'000'000, /* Probably only used to drive 68705 or similar MCUs on 80's Taito PCBs */
	  3'072'000, /* INS 8520 input clock rate */
	  3'120'000, /* SP0250 clock on Gottlieb games */
	  3'521'280, /* RCA COSMAC VIP */
	  3'570'000, /* Telmac TMC-600 */
	  3'578'640, /* Atari Portfolio PCD3311T */
	  3'579'545, /* NTSC color subcarrier, extremely common, used on 100's of PCBs (Keytronic custom part #48-300-010 is equivalent) */
	  3'686'400, /* Baud rate clock for MC68681 and similar UARTs */
	  3'840'000, /* Fairlight CMI Alphanumeric Keyboard */
	  3'900'000, /* Resonator - Used on some Fidelity boards */
	  4'000'000,
	  4'028'000, /* Sony SMC-777 */
	  4'032'000, /* GRiD Compass modem board */
	  4'096'000, /* Used to drive OKI M9810 chips */
	  4'194'304, /* Used to drive MC146818 / Nintendo Game Boy */
	  4'224'000, /* Used to drive OKI M6295 chips, usually with /4 divider */
	  4'410'000, /* Pioneer PR-8210 ldplayer */
	  4'433'610, /* Cidelsa Draco */
	  4'433'619, /* PAL color subcarrier (technically 4.43361875mhz)*/
	  4'608'000, /* Luxor ABC-77 keyboard (Keytronic custom part #48-300-107 is equivalent) */
	  4'915'200,
	  5'000'000, /* Mutant Night */
	  5'068'800, /* Usually used as MC2661 or COM8116 baud rate clock */
	  5'185'000, /* Intel INTELLEC® 4 */
	  5'460'000, /* ec1840 and ec1841 keyboard */
	  5'529'600, /* Kontron PSI98 keyboard */
	  5'626'000, /* RCA CDP1869 PAL dot clock */
	  5'670'000, /* RCA CDP1869 NTSC dot clock */
	  5'714'300, /* Cidelsa Destroyer, TeleVideo serial keyboards */
	  5'911'000, /* Philips Videopac Plus G7400 */
	  5'990'400, /* Luxor ABC 800 keyboard (Keytronic custom part #48-300-008 is equivalent) */
	  6'000'000, /* American Poker II, Taito SJ System */
	  6'144'000, /* Used on Alpha Denshi early 80's games sound board, Casio FP-200 and Namco Universal System 16 */
	  6'500'000, /* Jupiter Ace */
	  6'880'000, /* Barcrest MPU4 */
	  6'900'000, /* BBN BitGraph CPU */
	  7'000'000, /* Jaleco Mega System PCBs */
	  7'159'090, /* Blood Bros (2x NTSC subcarrier) */
	  7'372'800,
	  7'864'300, /* Used on InterFlip games as video clock */
	  8'000'000, /* Extremely common, used on 100's of PCBs */
	  8'200'000, /* Universal Mr. Do - Model 8021 PCB */
	  8'388'000, /* Nintendo Game Boy Color */
	  8'448'000, /* Banpresto's Note Chance - Used to drive OKI M6295 chips, usually with /8 divider */
	  8'467'200, /* Subsino's Ying Hua Lian */
	  8'664'000, /* Touchmaster */
	  8'700'000, /* Tandberg TDV 2324 */
	  8'867'236, /* RCA CDP1869 PAL color clock (~2x PAL subcarrier) */
	  8'867'238, /* ETI-660 (~2x PAL subcarrier) */
	  8'945'000, /* Hit Me */
	  9'216'000, /* Conitec PROF-180X */
	  9'828'000, /* Universal PCBs */
	  9'830'400, /* Epson PX-8 */
	  9'832'000, /* Robotron A7150 */
	  9'877'680, /* Microterm 420 */
	  9'987'000, /* Crazy Balloon */
	 10'000'000,
	 10'245'000, /* PES Speech box */
	 10'380'000, /* Fairlight Q219 Lightpen/Graphics Card */
	 10'500'000, /* Agat-7 */
	 10'595'000, /* Mad Alien */
	 10'687'500, /* BBC Bridge Companion */
	 10'694'250, /* Xerox 820 */
	 10'717'200, /* Eltec EurocomII */
	 10'730'000, /* Ruleta RE-900 VDP Clock */
	 10'733'000, /* The Fairyland Story */
	 10'738'635, /* TMS9918 family (3x NTSC subcarrier) */
	 10'816'000, /* Universal 1979-1980 (Cosmic Alien, etc) */
	 10'920'000, /* ADDS Viewpoint 60, Viewpoint A2 */
	 11'000'000, /* Mario I8039 sound */
	 11'059'200, /* Used with MCS-51 to generate common baud rates */
	 11'200'000, /* New York, New York */
	 11'289'000, /* Vanguard */
	 11'400'000, /* HP 9845 */
	 11'668'800, /* Gameplan pixel clock */
	 11'800'000, /* IBM PC Music Feature Card */
	 11'980'800, /* Luxor ABC 80 */
	 12'000'000, /* Extremely common, used on 100's of PCBs */
	 12'057'600, /* Poly 1 (38400 * 314) */
	 12'096'000, /* Some early 80's Atari games */
	 12'288'000, /* Sega Model 3 digital audio board */
	 12'324'000, /* Otrona Attache */
	 12'432'000, /* Kaneko Fly Boy/Fast Freddie Hardware */
	 12'472'500, /* Bonanza's Mini Boy 7 */
	 12'480'000, /* TRS-80 Model II */
	 12'500'000, /* Red Alert audio board */
	 12'800'000, /* Cave CV1000 */
	 12'854'400, /* alphatronic P3 */
	 12'979'200, /* Exidy 440 */
	 13'300'000, /* BMC bowling */
	 13'330'560, /* Taito L */
	 13'333'000, /* Ojanko High School */
	 13'400'000, /* TNK3, Ikari Warriors h/w */
	 13'478'400, /* TeleVideo 970 80-column display clock */
	 13'495'200, /* Used on Shadow Force pcb and maybe other Technos pcbs? */
	 13'516'800, /* Kontron KDT6 */
	 13'608'000, /* TeleVideo 910 & 925 */
	 14'000'000,
	 14'112'000, /* Timex/Sinclair TS2068 */
	 14'192'640, /* Central Data 2650 */
	 14'218'000, /* Dragon */
	 14'300'000, /* Agat-7 */
	 14'314'000, /* Taito TTL Board  */
	 14'318'181, /* Extremely common, used on 100's of PCBs (4x NTSC subcarrier) */
	 14'705'882, /* Aleck64 */
	 14'745'600, /* Namco System 12 & System Super 22/23 for JVS */
	 14'916'000, /* ADDS Viewpoint 122 */
	 15'000'000, /* Sinclair QL, Amusco Poker */
	 15'148'800, /* Zentec 9002/9003 */
	 15'288'000, /* DEC VT220 80-column display clock */
	 15'300'720, /* Microterm 420 */
	 15'360'000, /* Visual 1050 */
	 15'400'000, /* DVK KSM */
	 15'468'480, /* Bank Panic h/w, Sega G80 */
	 15'582'000, /* Zentec Zephyr */
	 15'897'600, /* IAI Swyft */
	 15'920'000, /* HP Integral PC */
	 15'974'400, /* Osborne 1 (9600 * 52 * 32) */
	 16'000'000, /* Extremely common, used on 100's of PCBs */
	 16'097'280, /* DEC VT240 (1024 * 262 * 60) */
	 16'128'000, /* Fujitsu FM-7 */
	 16'384'000,
	 16'400'000, /* MS 6102 */
	 16'588'800, /* SM 7238 */
	 16'669'800, /* Qume QVT-102 */
	 16'670'000,
	 16'777'216, /* Nintendo Game Boy Advance */
	 16'934'400, /* Usually used to drive 90's Yamaha OPL/FM chips (44100 * 384) */
	 17'064'000, /* Memorex 1377 */
	 17'360'000, /* OMTI Series 10 SCSI controller */
	 17'550'000, /* HP 264x display clock (50 Hz configuration) */
	 17'734'470, /* (~4x PAL subcarrier) */
	 17'734'472, /* actually ~4x PAL subcarrier */
	 17'971'200,
	 18'000'000, /* S.A.R, Ikari Warriors 3 */
	 18'432'000, /* Extremely common, used on 100's of PCBs (48000 * 384) */
	 18'575'000, /* Visual 102, Visual 220 */
	 18'720'000, /* Nokia MikroMikko 1 */
	 18'869'600, /* Memorex 2178 */
	 19'339'600, /* TeleVideo TVI-955 80-column display clock */
	 19'600'000, /* Universal Mr. Do - Model 8021 PCB */
	 19'660'800, /* Euro League (bootleg), labeled as "UKI 19.6608 20PF" */
	 19'661'400, /* Wyse WY-30 */
	 19'923'000, /* Cinematronics vectors */
	 19'968'000, /* Used mostly by some Taito games */
	 20'000'000,
	 20'160'000, /* Nintendo 8080 */
	 20'625'000, /* SM 7238 */
	 20'790'000, /* Blockade-hardware Gremlin games */
	 21'000'000, /* Lock-On pixel clock */
	 21'052'600, /* NEC PC-98xx pixel clock */
	 21'060'000, /* HP 264x display clock (60 Hz configuration) */
	 21'254'400, /* TeleVideo 970 132-column display clock */
	 21'281'370, /* Radica Tetris */
	 21'300'000,
	 21'477'272, /* BMC bowling, some Data East 90's games, Vtech Socrates; (6x NTSC subcarrier) */
	 22'000'000,
	 22'096'000, /* ADDS Viewpoint 122 */
	 22'118'400, /* Amusco Poker */
	 22'321'000, /* Apple LaserWriter II NT */
	 22'656'000, /* Super Pinball Action (~1440x NTSC line rate) */
	 22'896'000, /* DEC VT220 132-column display clock */
	 23'814'000, /* TeleVideo TVI-912, 920 & 950 */
	 23'961'600, /* Osborne 4 (Vixen) */
	 24'000'000, /* Mario, 80's Data East games, 80's Konami games */
	 24'073'400, /* DEC Rainbow 100 */
	 24'576'000, /* Pole Position h/w, Model 3 CPU board */
	 24'883'200, /* DEC VT100 */
	 25'000'000, /* Namco System 22, Taito GNET, Dogyuun h/w */
	 25'174'800, /* Sega System 16A/16B (1600x NTSC line rate) */
	 25'200'000, /* Tektronix 4404 video clock */
	 25'398'360, /* Tandberg TDV 2324 */
	 25'447'000, /* Namco EVA3A (Funcube2) */
	 25'590'906, /* Atari Jaguar NTSC */
	 25'593'900, /* Atari Jaguar PAL */
	 25'771'500, /* HP-2622A */
	 25'920'000, /* ADDS Viewpoint 60 */
	 26'000'000, /* Gaelco PCBs */
	 26'366'000, /* DEC VT320 */
	 26'580'000, /* Wyse WY-60 80-column display clock */
	 26'601'712, /* Astro Corp.'s Show Hand, PAL Vtech/Yeno Socrates (6x PAL subcarrier) */
	 26'666'000, /* Imagetek I4100/I4220/I4300 */
	 26'666'666, /* Irem M92 but most use 27MHz */
	 26'686'000, /* Typically used on 90's Taito PCBs to drive the custom chips */
	 26'989'200, /* TeleVideo 965 */
	 27'000'000, /* Some Banpresto games macrossp, Irem M92 and 90's Toaplan games */
	 27'164'000, /* Typically used on 90's Taito PCBs to drive the custom chips */
	 27'210'900, /* LA Girl */
	 27'562'000, /* Visual 220 */
	 28'000'000,
	 28'322'000, /* Saitek RISC 2500, Mephisto Montreux */
	 28'375'160, /* Amiga PAL systems */
	 28'475'000, /* CoCo 3 PAL */
	 28'480'000, /* Chromatics CGC-7900 */
	 28'636'363, /* Later Leland games and Atari GT, Amiga NTSC, Raiden2 h/w (8x NTSC subcarrier)*/
	 28'640'000, /* Fukki FG-1c AI AM-2 PCB */
	 28'700'000,
	 29'376'000, /* Qume QVT-103 */
	 29'491'200, /* Xerox Alto-II system clock (tagged 29.4MHz in the schematics) */
	 30'000'000, /* Impera Magic Card */
	 30'476'100, /* Taito JC */
	 30'800'000, /* 15IE-00-013 */
	 31'279'500, /* Wyse WY-30+ */
	 31'684'000, /* TeleVideo TVI-955 132-column display clock */
	 31'948'800, /* NEC PC-88xx, PC-98xx */
	 32'000'000,
	 32'220'000, /* Typically used on 90's Data East PCBs (close to 9x NTSC subcarrier which is 32.215905Mhz*/
	 32'317'400, /* DEC VT330, VT340 */
	 32'530'400, /* Seta 2 */
	 33'000'000, /* Sega Model 3 video board */
	 33'264'000, /* Hazeltine 1500 terminal */
	 33'333'000, /* Sega Model 3 CPU board, Vegas */
	 33'833'000,
	 33'868'800, /* Usually used to drive 90's Yamaha OPL/FM chips with /2 divider */
	 34'000'000, /* Gaelco PCBs */
	 34'291'712, /* Fairlight CMI master card */
	 36'000'000, /* Sega Model 1 video board */
	 38'769'220, /* Namco System 21 video board */
	 39'321'600, /* Sun 2/120 */
	 39'710'000, /* Wyse WY-60 132-column display clock */
	 40'000'000,
	 40'210'000, /* Fairlight CMI IIx */
	 42'000'000, /* BMC A-00211 - Popo Bear */
	 42'105'200, /* NEC PC-88xx */
	 42'954'545, /* CPS3 (12x NTSC subcarrier)*/
	 43'320'000, /* DEC VT420 */
	 44'100'000, /* Subsino's Bishou Jan */
	 44'452'800, /* TeleVideo 965 */
	 45'000'000, /* Eolith with Hyperstone CPUs */
	 45'158'000, /* Sega Model 2A video board, Model 3 CPU board */
	 45'619'200, /* DEC VK100 */
	 45'830'400, /* Microterm 5510 */
	 47'736'000, /* Visual 100 */
	 48'000'000, /* Williams/Midway Y/Z-unit system / SSV board */
	 48'384'000, /* Namco NB-1 */
	 48'556'800, /* Wyse WY-85 */
	 48'654'000, /* Qume QVT-201 */
	 48'660'000, /* Zaxxon */
	 49'152'000, /* Used on some Namco PCBs, Baraduke h/w, System 21, Super System 22  */
	 49'423'500, /* Wyse WY-185 */
	 50'000'000, /* Williams/Midway T/W/V-unit system */
	 50'113'000, /* Namco NA-1 (14x NTSC subcarrier)*/
	 50'349'000, /* Sega System 18 (~3200x NTSC line rate) */
	 52'000'000, /* Cojag */
	 52'832'000, /* Wang PC TIG video controller */
	 53'203'400, /* Master System, Mega Drive PAL (~12x PAL subcarrier) */
	 53'693'175, /* PSX-based h/w, Sony ZN1-2-based (15x NTSC subcarrier) */
	 54'000'000, /* Taito JC */
	 55'000'000, /* Eolith Vega */
	 57'272'727, /* Psikyo SH2 with /2 divider (16x NTSC subcarrier)*/
	 58'000'000, /* Magic Reel (Play System) */
	 59'292'000, /* Data General D461 */
	 60'000'000,
	 61'440'000, /* dkong */
	 64'000'000, /* BattleToads */
	 66'666'700, /* Later Midway games */
	 67'737'600, /* PSX-based h/w, Sony ZN1-2-based */
	 68'850'000, /* Wyse WY-50 */
	 72'000'000, /* Aristocrat MKV */
	 72'576'000, /* Centipede, Millipede, Missile Command, Let's Go Bowling "Multipede" */
	 73'728'000, /* Ms. Pac-Man/Galaga 20th Anniversary */
	 87'183'360, /* AT&T 630 MTG */
	100'000'000, /* PSX-based Namco System 12, Vegas, Sony ZN1-2-based */
	101'491'200, /* PSX-based Namco System 10 */
	200'000'000  /* Base SH4 CPU (Naomi, Hikaru etc.) */
};

double XTAL::last_correct_value = -1;
double XTAL::xtal_error_low = 0;
double XTAL::xtal_error_high = 0;

bool XTAL::validate(double base_clock)
{
	if(base_clock == last_correct_value)
		return true;
	const unsigned int xtal_count = sizeof(known_xtals) / sizeof(known_xtals[0]);
	const unsigned int last_index = xtal_count - 1;
	const unsigned int fill1  = last_index | (last_index >> 1);
	const unsigned int fill2  = fill1 | (fill1 >> 2);
	const unsigned int fill4  = fill2 | (fill2 >> 4);
	const unsigned int fill8  = fill4 | (fill4 >> 8);
	const unsigned int fill16 = fill8 | (fill8 >> 16);
	const unsigned int ppow2  = fill16 - (fill16 >> 1);
	unsigned int slot = ppow2;
	unsigned int step = ppow2;
	while(step) {
		if(slot > last_index)
			slot = slot ^ (step | (step >> 1));
		else {
			double sfreq = known_xtals[slot];
			if(base_clock == sfreq) {
				last_correct_value = base_clock;
				return true;
			}
			if(base_clock > sfreq)
				slot = slot | (step >> 1);
			else
				slot = slot ^ (step | (step >> 1));
		}
		step = step >> 1;
	}
	
	double sfreq = known_xtals[slot];
	if(base_clock == sfreq) {
		last_correct_value = base_clock;
		return true;
	}

	if(base_clock < sfreq) {
		if(slot)
			xtal_error_low = known_xtals[slot-1];
		else
			xtal_error_low = 0;
		xtal_error_high = sfreq;
	} else {
		if(slot < last_index)
			xtal_error_high = known_xtals[slot+1];
		else
			xtal_error_high = 0;
		xtal_error_low = sfreq;
	}
	return false;
}

void XTAL::validate(const char *message) const
{
	if(!validate(m_base_clock))
		fail(m_base_clock, message);
}

void XTAL::validate(const std::string &message) const
{
	if(!validate(m_base_clock))
		fail(m_base_clock, message);
}

void XTAL::fail(double base_clock, std::string message)
{
	std::string full_message = util::string_format("Unknown crystal value %.0f. ", base_clock);
	if(xtal_error_low && xtal_error_high)
		full_message += util::string_format(" Did you mean %.0f or %.0f?", xtal_error_low, xtal_error_high);
	else
		full_message += util::string_format(" Did you mean %.0f?", xtal_error_low ? xtal_error_low : xtal_error_high);
	full_message += util::string_format(" Context: %s\n", message);
	fatalerror("%s\n", full_message.c_str());
}

/*

For further reference:

A search at http://search.digikey.com/scripts/DkSearch/dksus.dll?Cat=852333;keywords=cry
reveals the following shipping frequencies as of 1/1/2008:

20kHz
25.600kHz
26.667kHz
28kHz

30kHz
30.720kHz
30.76kHz
31.2kHz
31.25kHz
31.5kHz
32.000kHz
32.56kHz
32.768kHz
32.919kHz
34kHz
36kHz
38kHz
38.4kHz
39.500kHz

40kHz
44.100kHz
46.604kHz
46.6084kHz

50kHz
59.787kHz

60.000kHz
60.002kHz
60.005kHz
65.535kHz
65.536kHz
69kHz

70kHz
71kHz
72kHz
73kHz
74kHz
74.3kHz
74.4kHz
75kHz
76kHz
76.79kHz
76.8kHz
76.81kHz
77kHz
77.204kHz
77.287kHz
77.500kHz
77.503kHz
77.504kHz
78kHz
79kHz

83kHz

96kHz
96.006kHz

100kHz
111kHz
117.72kHz
120kHz
120.8475kHz
125kHz
131.072kHz
149.475kHz
153.600kHz

200kHz

307.2kHz

1.000MHz
1.8432MHz

2.000MHz
2.048MHz
2.097152MHz
2.4576MHz
2.5MHz
2.560MHz
2.949120MHz

3.000MHz
3.276MHz
3.2768MHz
3.579MHz
3.579545MHz
3.640MHz
3.6864MHz
3.700MHz
3.859MHz
3.93216MHz

4.000MHz
4.032MHz
4.096MHz
4.09625MHz
4.194MHz
4.194304MHz
4.332MHz
4.433MHz
4.433616MHz
4.433618MHz
4.433619MHz
4.74687MHz
4.800MHz
4.8970MHz
4.90625MHz
4.915MHz
4.9152MHz

5.000MHz
5.0688MHz
5.120MHz
5.223438MHz
5.5MHz
5.5296MHz
5.9904MHz

6.000MHz
6.14MHz
6.144MHz
6.1760MHz
6.400 MHz
6.49830MHz
6.5MHz
6.5536MHz
6.612813MHz
6.7458MHz
6.757MHz
6.76438MHz

7.1505MHz
7.15909 MHz
7.2MHz
7.3728MHz
7.68MHz
7.94888MHz

8.000MHz
8.000156MHz
8.192MHz
8.388608MHz
8.432MHz
8.5MHz
8.6432MHz

9.000MHz
9.216MHz
9.509375MHz
9.545MHz
9.6MHz
9.7941MHz
9.830MHz
9.8304MHz
9.84375MHz
9.8438MHz

10.000MHz
10.240MHz
10.245MHz
10.6244MHz
10.738635MHz
10.73865MHz

11.000MHz
11.046MHz
11.0592MHz
11.228MHz
11.2896MHz
11.520MHz
11.981350MHz

12.000MHz
12.000393MHz
12.096MHz
12.1875MHz
12.288MHz
12.352MHz
12.500MHz
12.688MHz
12.800MHz
12.96MHz

13.000MHz
13.0625MHz
13.225MHz
13.2256MHz
13.500MHz
13.5168MHz
13.56MHz
13.605MHz
13.824MHz
13.94916MHz

14.00MHz
14.318MHz
14.31818MHz
14.3359MHz
14.3594MHz
14.4MHz
14.5MHz
14.69MHz
14.7456MHz
14.850MHz

15MHz
15.360MHz

16.000MHz
16.000312MHz
16.128MHz
16.257MHz
16.3676MHz
16.368MHz
16.384MHz
16.576MHz
16.6660MHz
16.667MHz
16.670MHz
16.800MHz
16.934MHz
16.9344MHz

17.734475MHz

18.000MHz
18.432MHz
18.869MHz

19.200MHz
19.440MHz
19.660MHz
19.6608MHz
19.68MHz
19.800MHz

20.000MHz
20.35625MHz
20.3563MHz
20.480MHz

21.47727MHz

22.000MHz
22.118MHz
22.1184MHz
22.400MHz
22.5MHz
22.5792MHz
22.6278MHz

23MHz
23.2643MHz
23.5MHz
23.5122MHz
23.592MHz

24.000MHz
24.00014MHz
24.5MHz
24.545454 MHz
24.5535MHz
24.576MHz
24.704MHz
24.7456MHz

25.000MHz
25MHz
25.175MHz
25.2235MHz
25.4563MHz
25.5MHz

26.000MHz
26.45125MHz
26.4513MHz
26.5MHz
26.5971MHz
26.800MHz

27.000MHz
27.1344MHz
27.3067MHz
27.4688MHz

28.000MHz
28.224MHz
28.259375MHz
28.2594MHz
28.322MHz
28.375MHz
28.5938MHz
28.636MHz
28.6363MHz
28.63636MHz

29.4912MHz
29.498928MHz
29.500MHz

30.000MHz
32.000MHz
32.514MHz
32.768MHz
33.000MHz
33.333MHz
33.3333MHz
33.8688MHz
35.2512MHz
35.3280MHz
36.000MHz
38.000MHz
38.00053MHz
38.400MHz
38.880MHz
39MHz

40.000MHz
40.320MHz
40.960 MHz
42.000MHz
44.000MHz
44.2368MHz
44.545MHz
44.736MHz
44.800MHz
44.900MHz
45.000MHz
46.000MHz
48.000MHz
49.152MHz
49.86MHz

50.000MHz
53.125MHz
55.000MHz

60.000MHz
64.000MHz
66.000MHz
66.666MHz
66.6666MHz

73.66979MHz
75.957292MHz
76.121875MHz

80.000MHz

100.00MHz

*/
