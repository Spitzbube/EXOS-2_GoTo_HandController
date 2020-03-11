
	//See: https://github.com/engerim42/wmsolar/blob/master/Pluto.cpp
	//See: home.mnet-online.de/reimay/Projects/pc/Astronomie/libaa/AAPluto.cpp
	
/* 1a2d0 - todo */
double pluto_ecliptic_longitude(double a)
{
	double sp120 = 0.0;
	double J;
	double S;
	double P;
	double sp88;
	
	J = 34.35 + a * 3034.9057;
	S = 50.08 + a * 1222.1138;
	P = 238.96 + a * 144.96;
	
	sp120 += sin(1.0 * P / 180.0 * 3.1415927) * -19798886 + 
		cos(1.0 * P / 180.0 * 3.1415927) * 19848454;
	sp120 += sin(2.0 * P / 180.0 * 3.1415927) * 897499 - 
		cos(2.0 * P / 180.0 * 3.1415927) * 4955707;
	
	sp88 = a * 144.96 + 238.956785 + sp120 / 1000000;
	
	return sp88;
}

/* 1a680 - todo */
double pluto_ecliptic_latitude(double a)
{
	double sp120 = 0.0;
	double J;
	double S;
	double P;
	double sp88;
	
	J = 34.35 + a * 3034.9057;
	S = 50.08 + a * 1222.1138;
	P = 238.96 + a * 144.96;
	
	sp120 += sin(1.0 * P / 180.0 * 3.1415927) * -5453098 - 
		cos(1.0 * P / 180.0 * 3.1415927) * 14974876;
	sp120 += sin(2.0 * P / 180.0 * 3.1415927) * 3527363 + 
		cos(2.0 * P / 180.0 * 3.1415927) * 1672673;
	sp120 += sin(3.0 * P / 180.0 * 3.1415927) * -1050939 + 
		cos(3.0 * P / 180.0 * 3.1415927) * 327763;
	
	sp88 = -3.908202 + sp120 / 1000000;
	
	return sp88;
}

/* 1aac4 - todo */
double pluto_radius_vector(double a)
{
	double sp120 = 0.0;
	double J;
	double S;
	double P;
	double sp88;
	
	J = a * 3034.9057 + 34.35;
	S = a * 1222.1138 + 50.08;
	P = a * 144.96 + 238.96;
	
	sp120 += sin((1.0 * P) / 180.0 * 3.1415927) * 66867334.0 + 
		cos((1.0 * P) / 180.0 * 3.1415927) * 68955876.0;
	sp120 += sin((2.0 * P) / 180.0 * 3.1415927) * -11826086 -
		cos((2.0 * P) / 180.0 * 3.1415927) * 333765;
	sp120 += sin(3.0 * P / 180.0 * 3.1415927) * 1593657 -
		cos(3.0 * P / 180.0 * 3.1415927) * 1439953;
	
	sp88 = 40.7247248 + sp120 / 10000000;
	
	return sp88;
}

