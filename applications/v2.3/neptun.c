
/* 19118 - todo */
double neptune_ecliptic_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double res = 0.0;
	
	L0 += 531188633 * cos(0 + a * 0);
	L0 += 1798476 * cos(2.9010127 + a * 38.1330356);
	L0 += 1019728 * cos(0.4858092 + a * 1.4844727);
	L0 += 124532 * cos(4.830081 + a * 36.648563);
	L0 += 42064 * cos(5.41055 + a * 2.96895);
	L0 += 37715 * cos(6.09222 + a * 35.16409);

	L1 += 3837687717 * cos(0 + a * 0);

	L2 += 53893 * cos(0 + a * 0);

	res = (L0 + L1 * a + L2 * a*a + L3 * a*a*a + L4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 196cc - todo */
double neptune_ecliptic_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double B2 = 0.0;
	double B3 = 0.0;
	double B4 = 0.0;
	double res = 0.0;
	
	B0 += 3088623 * cos(1.4410437 + a * 38.1330356);
	B0 += 27780 * cos(5.91272 + a * 76.26607);
	B0 += 27624 * cos(0 + a * 0);
	B0 += 15448 * cos(3.50877 + a * 39.61751);
	B0 += 15355 * cos(2.52124 + a * 36.64856);

	B1 += 227279 * cos(3.807931 + a * 38.133036);
	
//	B2 += 9691 * cos(5.5712 + a * 38.1330); 
	B2 += 273 * cos(1.107 + a * 38.1330); //BUG!
	
	res = (B0 + B1 * a + B2 * a*a + B3 * a*a*a + B4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 19c18 - todo */
double neptune_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double res = 0.0;
	
	R0 += 3007013206 * cos(0 + a * 0); 
	R0 += 27062259 * cos(1.32999459 + a * 38.13303364); //38.13303564); //BUG?
	R0 += 1691764 * cos(3.2518614 + a * 36.6485629);
	R0 += 807831 * cos(5.185928 + a * 1.484473 );
	R0 += 537761 * cos(4.521139 + a * 35.164090);
	R0 += 495726 * cos(1.571057 + a * 491.557929);
	R0 += 274572 * cos(1.845523 + a * 175.166060);

	R1 += 236339 * cos(0.704980 + a * 38.133036);
	R1 += 13220 * cos(3.32015 + a * 1.48447);
	R1 += 8622 * cos(6.2163 + a * 35.1641);

	R2 += 4247 * cos(5.8991 + a * 38.1330);
	
	res = (R0 + R1 * a + R2 * a*a + R3 * a*a*a) / 100000000.0;
		
	return res;
}

