
unsigned char strAlignStarsNames[][10] = //40000000
{
	"Sirius   ",
	"Canopus  ",
	"Vega     ",
	"Alpha Cen",
	"Arcturus ",
	"Capella  ",
	"Rigel    ",
	"Procyon  ",
	"Achernar ",
	"Betelgeus",
	"Altair   ",
	"Aldebaran",
	"Spica    ",
	"Antares  ",
	"Fomalhaut",
	"Deneb    ",
	"Regulus  ",
	"Mirfak   ",
	"Castor   ",
	"Alphard  ",
	"Polaris  ",
	"Alpheratz",
	"Rasalhagu",
	"Denebola ",
	"Navi     ",
	"Suhail   ",
	"Mizar    ",
	"Albireo  "
}; 

unsigned char Data_40000118[][22] = //40000118
{
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
	"                     ",
};

/* 58ec - complete */
unsigned char GetCurrentAlignStars(float r4, float r5, float* equatorialCoord, unsigned char strNames[][10], unsigned char sp304[][22])
{
	int i; 
	unsigned char cnt;
	unsigned char j;
	
	float ra[28];
	float dec[28];
	unsigned char visible[20]; //size??
	unsigned char k;
	float sp16, sp12, sp8, sp4;

	ra[0] = 6.75850009918212890625; //Sirius - Alpha CMa
	dec[0] = -16.7263050079345703125;
	ra[1] = 6.40180301666259765625; //Canopus - Alpha Car
	dec[1] = -52.69824981689453125;
	ra[2] = 18.620929718017578125; //Vega - Alpha Lyr
	dec[2] = 38.790943145751953125;
	ra[3] = 14.6703472137451171875; // Rigil Kentaurus / Toliman  - Alpa Cen
	dec[3] = -60.875278472900390625;
	ra[4] = 14.26785564422607421875; //Arcturus - Alpha Boo
	dec[4] = 19.1384716033935546875;
	ra[5] = 5.288404941558837890625; //Capella - Alpha Aur
	dec[5] = 46.0066375732421875;
	ra[6] = 5.248960971832275390625; //Rigel - Beta Ori
	dec[6] = -8.18952846527099609375;
	ra[7] = 7.662292003631591796875; //Procyon - Alpha CMi
	dec[7] = 5.204332828521728515625;
	ra[8] = 1.63397800922393798828125; //Achernar - Alpha Eri
	dec[8] = -57.187053680419921875;
	ra[9] = 5.09371089935302734375; //Betelgeuse - Alpa Ori
	dec[9] = 7.410167217254638671875;
	ra[10] = 19.8538360595703125; //Altair - Alpha Aql
	dec[10] = 8.890472412109375;
	ra[11] = 4.60669994354248046875; //Aldebaran - Alpha Tau
	dec[11] = 16.52752685546875;
	ra[12] = 13.4276142120361328125; //Spica - Alpha Vir
	dec[12] = -11.2079448699951171875;
	ra[13] = 16.49939727783203125; //Antares - Alpha Sco
	dec[13] = -26.4533329010009765625;
	ra[14] = 22.9691143035888671875; //Formalhaut - Alpha PsA
	dec[14] = -29.5733890533447265625;
	ra[15] = 20.6958770751953125; //Deneb - Alpha Cyg
	dec[15] = 45.308834075927734375;
	ra[16] = 10.14705562591552734375; //Regulus - Alpha Leo
	dec[16] = 11.9264163970947265625;
	ra[17] = 3.41538906097412109375; //Mirfak - Alpha Per
	dec[17] = 49.890056610107421875;
	ra[18] = 7.5854969024658203125; //Castor - Alpha Gem
	dec[18] = 31.87105560302734375;
	ra[19] = 9.46664142608642578125; //Alphard - Alpha Hya
	dec[19] = -8.69580554962158203125;
	ra[20] = 2.6790111064910888671875; //Polaris - Alpha UMi
	dec[20] = 89.2981109619140625;
	ra[21] = 0.1473419964313507080078125; //Sirrah / Alpheratz - Alpha And
	dec[21] = 29.136417388916015625;
	ra[22] = 17.5893688201904296875; //Rasalhagu - Alpha Oph
	dec[22] = 12.55330562591552734375;
	ra[23] = 11.82501697540283203125; //Denebola - Beta Leo
	dec[23] = 14.52511119842529296875;
	ra[24] = 0.953800022602081298828125; //Navi / Tsih / 27 Cas - Gamma Cas
	dec[24] = 60.759693145751953125;
	ra[25] = 9.13812732696533203125; //Suhail - Lambda Velorum
	dec[25] = -43.468776702880859375;
	ra[26] = 13.40486621856689453125; //Mizar - Zeta UMa
	dec[26] = 54.884029388427734375;
	ra[27] = 19.51886749267578125; //Albireo - Beta Cyg
	dec[27] = 27.982250213623046875;
	
	if ((r4 >= 4) || (r4 <= 20))
	{
		sp8 = r4 - 4;
		sp4 = r4 + 4;
	}
	//5c10
	else if (r4 < 4)
	{
		sp8 = r4 + 24 - 4;
		sp4 = r4 + 4;
	}
	else
	{
		sp8 = r4 - 4;
		sp4 = r4 - 24 + 4;
	}
	//5c7c
	if (r5 >= 0)
	{
		sp16 = r5 - 60;
		sp12 = r5 + 60;
		
		if (sp12 > 90)
		{
			sp12 = 90;
		}
	}
	else
	{
		//5cc8
		sp16 = r5 - 60;
		sp12 = r5 + 60;
		
		if (sp16 < -90)
		{
			sp16 = -90;
		}
	}
	//5d00
	i = 0;
	cnt = 0; 
	for (; i < 28; i++)
	{
		//5d0c
		if ((r4 >= 4) || (r4 <= 20))
		{
			//5d2c
			if ((ra[i] >= sp8) && (ra[i] <= sp4) &&
				(dec[i] >= sp16) && (dec[i] <= sp12))
			{
				visible[cnt] = i;
				cnt++;
			}
		}
		else
		{
			//5d90
			if ((r4 <= 4) || (r4 >= 20))
			{
				//5db0
				if (((ra[i] >= sp8) && (ra[i] <= 24)) ||
					((ra[i] >= 0) && (ra[i] <= sp4)))
				{
					//5e00
					if ((dec[i] >= sp16) && (dec[i] <= sp12))
					{
						//5e28
						visible[cnt] = i;
						cnt++;
					}
				}
			}
		}		
	}
	//5e44
	if (cnt > 0)
	{
		for (i = 0; i <= (cnt-1); i++)
		{
			//5e54
			*(equatorialCoord + i*2)     = ra[ visible[i] ];
			*(equatorialCoord + i*2 + 1) = dec[ visible[i] ];
			
			for (j = 0; j < 10; j++)
			{
				//5e8c
				strNames[i][j] = strAlignStarsNames[visible[i]][j];
			}
			//5ec0
			for (k = 0; k < 22; k++)
			{
				//5ecc
				sp304[i][k] = Data_40000118[visible[i]][k];
			}
		}		
	}
	//5f2c
	return cnt-1;
}

