
//For the following see: https://pymeeus.readthedocs.io/en/latest/Earth.html
//https://www.avrfreaks.net/forum/best-microcontroller-heavy-computation?page=all

/* e11c - complete */
double earth_heliocentric_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double L5 = 0.0;
	double res = 0.0;

	L0 += 175347046 * cos(0.0 + a * 0.0);
	L0 += 3341656 * cos(4.6692568 + a * 6283.07585); 
	L0 += 34894 * cos(4.6261 + a * 12566.1517); 
	L0 += 3497 * cos(2.7441 + a * 5753.3849);
	L0 += 3418 * cos(2.8289 + a * 3.5231);
	L0 += 3136 * cos(3.6277 + a * 77713.7715);
	
	L1 += 628331966747 * cos(0.0 + a * 0.0);
	L1 += 206059 * cos(2.678235 + a * 6283.07585);
	L1 += 4303 * cos(2.6351 + a * 12566.1517);
	
	L2 += 52919 * cos(0.0 + a * 0.0);
	L2 += 8720 * cos(1.0721 + a * 6283.0758);
		
	res = (L0 +
		L1 * a +
		L2 * a*a + 
		L3 * a*a*a + 
		L4 * a*a*a*a + 
		L5 * a*a*a*a*a) / 100000000.0;
	
	return res;
}

/* e8fc - complete */
double earth_heliocentric_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double res = 0.0;
	
	B0 += 280.0 * cos(3.199 + a * 84334.662);
	B0 += 102.0 * cos(5.422 + a * 5507.553);
	B0 += 80.0 * cos(3.88 + a * 5223.69);
	B0 += 44.0 * cos(3.7 + a * 2352.87);
	B0 += 32.0 * cos(4 + a * 1577.34);
	
	B1 += 9.0 * cos(3.9 + a * 5507.55);
	B1 += 6.0 * cos(1.73 + a * 1577.34); //5223.69); //BUG!!!
	
	res = (B0 + B1 * a) / 100000000.0;
	
	return res;
}

/* ecf8 - complete */
double earth_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double R4 = 0.0;
	double res = 0.0;
	
	R0 += 100013989 * cos(0.0 + a * 0.0);
	R0 += 1670700 * cos(3.0984635 + a * 6283.07585);
	R0 += 13956 * cos(3.05525 + a * 12566.1517);
	R0 += 3084 * cos(5.1985 + a * 77713.7715);
	
	R1 += 103019 * cos(1.10749 + a * 6283.07585);
	R1 += 1721 * cos(1.0644 + a * 12566.1517);
	
	R2 += 4359 * cos(5.7846 + a * 6283.0758);
	
	res = (R0 +
		R1 * a +
		R2 * a*a + 
		R3 * a*a*a + 
		R4 * a*a*a*a) / 100000000.0;
		
	return res;
}

