
//http://home.mnet-online.de/reimay/Projects/pc/Astronomie/libaa/AAMercury.cpp

/* f22c - todo */
double mercury_ecliptic_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double L5 = 0.0;
	double res = 0.0;
	
	L0 += 440250710 * cos(0.0 + a * 0.0);
	L0 += 40989415 * cos(1.48302034 + a * 26087.90314157);
	L0 += 5046294 * cos(4.4778549 + a * 52175.8062831);
	L0 += 855347 * cos(1.165203 + a * 78263.709425);
	L0 += 165590 * cos(4.119692 + a * 104351.612566);
	L0 += 34562 * cos(0.77931 + a * 130439.51571);
	L0 += 7583 * cos(3.7135 + a * 156527.4188);
	L0 += 3560 * cos(1.5120 + a * 1109.3786);
	
	L1 += 2608814706223 * cos(0.0 + a * 0.0);
	L1 += 1126008 * cos(6.2170397 + a * 26087.9031416);
	L1 += 303471 * cos(3.055655 + a * 52175.806283);
	L1 += 80538 * cos(6.10455 + a * 78263.70942);
	L1 += 21245 * cos(2.83532 + a * 104351.61257);
	
	L2 += 53050 * cos(0.0 + a * 0.0);
	L2 += 16904 * cos(4.69072 + a * 26087.90314);
	
	res = (L0 +
		L1 * a +
		L2 * a*a + 
		L3 * a*a*a + 
		L4 * a*a*a*a +
		L5 * a*a*a*a*a) / 100000000.0;
		
	return res;
}

/* fc20 - todo */
double mercury_ecliptic_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double B2 = 0.0;
	double B3 = 0.0;
	double B4 = 0.0;
	double res = 0.0;
	
	B0 += 11737529 * cos(1.98357499 + a * 26087.90314157);
	B0 += 2388077 * cos(5.0373896 + a * 52175.8062831);
	B0 += 1222840 * cos(3.1415927 + a * 0.0);
	B0 += 543252 * cos(1.796444 + a * 78263.709425);
	B0 += 129779 * cos(4.832325 + a * 104351.612566);
	B0 += 31867 * cos(1.58088 + a * 130439.51571);
	
	B1 += 429151 * cos(3.501698 + a * 26087.903142);
	B1 += 146234 * cos(3.141593 + a * 0.0);
	B1 += 22675 * cos(0.01515 + a * 52175.80628);
	
	B2 += 11831 * cos(4.79066 + a * 26087.90314);
	B2 += 1914 * cos(0.0 + a * 0.0);
	B2 += 1045 * cos(1.2122 + a * 52175.8063);
	
	res = (B0 +
		B1 * a +
		B2 * a*a + 
		B3 * a*a*a + 
		B4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 103dc - todo */
double mercury_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double res = 0.0;
	
	R0 += 39528272 * cos(0.0 + a * 0.0);
	R0 += 7834132 * cos(6.1923372 + a * 26087.9031416);
	R0 += 795526 * cos(2.959897 + a * 52175.806283);
	R0 += 121282 * cos(6.010642 + a * 78263.709425);
	R0 += 21922 * cos(2.77820 + a * 104351.61257);

	R1 += 217348 * cos(4.656172 + a * 26087.9031416); //26087.903142); //BUG???
	R1 += 44142 * cos(1.42386 + a * 52175.80628);
	R1 += 10094 * cos(4.47466 + a * 8263.70942); //78263.70942); //BUG???
	
	R2 += 3118 * cos(3.0823 + a * 26087.9031);
	R2 += 1245 * cos(6.1518 + a * 52175.8063);
	R2 += 425 * cos(2.926 + a * 78263.709);
	R2 += 136 * cos(5.98 + a * 104351.613);
	
	res = (R0 +
		R1 * a +
		R2 * a*a + 
		R3 * a*a*a) / 100000000.0;
		
	return res;
}
