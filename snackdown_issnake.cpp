#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t,n;
	cin>>t;
	string str;
	std::vector<int> v;
	v.push_back(0);//0
	v.push_back(100);
	v.push_back(0);//1
	v.push_back(100);
	v.push_back(0);//4
	v.push_back(100);
	v.push_back(0);//5
	v.push_back(100);
	v.push_back(0);//6
	v.push_back(4);
	v.push_back(5);
	//v.push_back(7);//7 with 2 #
	v.push_back(23);//denotes 7 with 2 #
	//v.push_back(7);
	v.push_back(24);//7 with 3#
	v.push_back(9);
	v.push_back(10);
	v.push_back(100);//end of 6's dictionary
	v.push_back(0);//7's dict
	v.push_back(4);
	v.push_back(5);
	v.push_back(23);
	v.push_back(24);
	v.push_back(9);
	v.push_back(10);
	v.push_back(100);//end of 7 2# dict
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(6);
	v.push_back(8);
	v.push_back(10);
	v.push_back(100);
	v.push_back(0);//8
	v.push_back(4);
	v.push_back(5);
	v.push_back(23);
	v.push_back(24);
	v.push_back(9);
	v.push_back(10);
	v.push_back(100);
	v.push_back(0);//9's dict
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(6);
	v.push_back(8);
	v.push_back(10);
	v.push_back(100);
	v.push_back(0);//10
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(23);
	v.push_back(24);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	v.push_back(100);

	int a[25]={0};
	a[0] = 0;
	a[1] = 2;
	a[4] = 4;
	a[5] = 6;
	a[6] = 8;
	a[23] = 16;
	a[24] = 24;
	a[8] = 32;
	a[9] = 40;
	a[10] = 48;

//std::vector<int>::iterator it;


cout<<"size of v = "<<v.size()<<endl;
cout<<"list : "<<v[a[0]]<<endl;
cout<<"list : "<<v[a[1]]<<endl;
cout<<"list : "<<v[a[4]]<<endl;
cout<<"list : "<<v[a[5]]<<endl;
cout<<"list : "<<v[a[6]]<<endl;
cout<<"list : "<<v[a[23]]<<endl;
cout<<"list : "<<v[a[24]]<<endl;
cout<<"list : "<<v[a[8]]<<endl;
cout<<"list : "<<v[a[9]]<<endl;
cout<<"list : "<<v[a[10]]<<endl;

	for (int i = 0; i < t; ++i)
	{
		scanf("%d",&n);
		//int pos;
		char arr[2][n];
		cin>>str;
		for (int j = 0; j < n; ++j)
		{
			arr[0][j] = str[j];
		}
		cin>>str;
		for (int j = 0; j < n; ++j)
		{
			arr[1][j] = str[j];
		}

		for (int k = 0; k < n; ++k)
		{
			if(k%2 == 0)
				{
					if(arr[0][k] == '#')
						arr[0][k] = '1';
					else
						arr[0][k] = '0';

				}
			else{
					if(arr[0][k] == '#')
						arr[0][k] = '2';
					else
						arr[0][k] = '0';
			}


		}

		for (int k = 0; k < n; ++k)
		{
			if(k%2 == 0)
				{
					if(arr[1][k] == '#')
						arr[1][k] = '4';
					else
						arr[1][k] = '0';

				}
			else{
					if(arr[1][k] == '#')
						arr[1][k] = '3';
					else
						arr[1][k] = '0';
			}


		}

for (int k = 0; k < 2 ; ++k)
{
	for (int l = 0; l < n ; ++l)
	{
		printf("%c ",arr[k][l]);
	}
	printf("\n");

}
		int flag = 0;
		int sum = 0;
		int temp = -1;
		int legit_flag = 0;
		int temp2 = 0;
		for (int k = 0; k < n; k+=2)
		{
			
			if((arr[0][k] !='0' || arr[1][k] !='0') && flag == 0)
				{
					flag  = 1;
					
				}

			if(flag == 1 )
			{

					if(k+1 < n)
						{
							sum = (int)arr[0][k] - 48 + (int)arr[0][k+1] - 48 + (int)arr[1][k] - 48 + (int)arr[1][k+1] - 48;


						}
					else
						sum = (int)arr[0][k] - 48 + (int)arr[1][k] - 48;
						printf("k = %d : sum = %d\n",k,sum);
					if(n==1)
						legit_flag = 1;
					if(n==2)
					{
						if(!(sum == 4 && arr[0][k]=='1' && arr[1][k+1]=='3') || (sum == 6 && arr[0][k+1]=='2' && arr[1][k]=='4'))
							legit_flag = 1;
						
					}
					if(temp != -1)
					{
						if(temp == 7)
						{	if(((int)arr[0][k-2] - 48 + (int)arr[1][k-2] - 48  + (int)arr[0][k-1] - 48) == 7)
								temp2 = a[24];
							else
								temp2 = a[23];
						}
						else
							temp2 = a[temp];

						while(v[temp2]!=100)
							{
								if(sum == v[temp2])
									{
										legit_flag = 1;
										break;
									}

								temp2++;
							}
							if(legit_flag == 0)
								break;

					}
					temp = sum;





			}

		}
		if(legit_flag == 1)
			printf("yes\n");
		else
			printf("no\n");





	}
	return 0;
}
