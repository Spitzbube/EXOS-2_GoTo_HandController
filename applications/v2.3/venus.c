
/* 10b2c - todo */
double venus_ecliptic_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double L5 = 0.0;
	double res = 0.0;
	
	L0 += 317614667 * cos(0.0 + a * 0.0);
	L0 += 1353968 * cos(5.5931332 + a * 10213.2855462);
	L0 += 89892 * cos(5.30650 + a * 20426.57109);
	L0 += 5477 * cos(4.4163 + a * 7860.4194);
	
	L1 += 1021352943053 * cos(0.0 + a * 0.0);
	L1 += 95708 * cos(2.46424 + a * 10213.28555);
	L1 += 14445 * cos(0.51625 + a * 20426.57109);
	
	L2 += 54127 * cos(0.0 + a * 0.0);
	L2 += 3891 * cos(0.3451 + a * 10213.2855);
	L2 += 1338 * cos(2.0201 + a * 20426.5711);
	
	res = (L0 +
		L1 * a +
		L2 * a*a + 
		L3 * a*a*a +
		L4 * a*a*a*a +
		L5 * a*a*a*a*a) / 100000000.0;
		
	return res;
}

/* 1127c - todo */
double venus_ecliptic_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double B2 = 0.0;
	double B3 = 0.0;
	double B4 = 0.0;
	double res = 0.0;
	
	B0 += 5923638 * cos(0.2670278 + a * 10213.2855462);
	B0 += 40108 * cos(1.14737 + a * 20426.57109);
	B0 += 32815 * cos(3.14159 + a * 0.0);
	
	B1 += 513348 * cos(1.803643 + a * 10213.285546);
	B1 += 4380 * cos(3.3862 + a * 20426.5711);
	
	B2 += 22378 * cos(3.38509 + a * 10213.28555);
	
	res = (B0 + B1 * a + B2 * a*a + B3 * a*a*a + B4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 1173c - todo */
double venus_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double R4 = 0.0;
	double res = 0.0;
	
	R0 += 72334821 * cos(0.0 + a * 0.0);
	R0 += 489824 * cos(4.021518 + a * 10213.285546);

	R1 += 34551 * cos(0.89199 + a * 10213.28555);

	R2 += 1407 * cos(5.0637 + a * 10213.2855);
	
	res = (R0 + R1 * a + R2 * a*a + R3 * a*a*a + R4 * a*a*a*a) / 100000000.0;
		
	return res;
}

