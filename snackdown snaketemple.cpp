#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t,ele;
	scanf("%d",&t);
	std::vector<int> v;
	std::vector<int> sum;
	//

	for (int i = 0; i < t; ++i)
	{
		int n;
		scanf("%d",&n);
		//int temp=0;

		for (int j = 0; j < n ; ++j)
		{
			scanf("%d",&ele);
			v.push_back(ele);
			if(j == 0)
				sum.push_back(ele);
			else
			//{ 
				//temp=ele + v[j-1];
				sum.push_back(ele + sum[j-1]);
			//}

		}
		for (int j = 0; j < n; ++j)
		{
			printf("v[%d] = %d : sum[%d] = %d\n",j,v[j],j,sum[j]);
		}

		int flag = 0;//used to check if already smaller than the desired
		int temp_cost=0,cost=INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			for (int k = 3; j+k < n; k+=2)
			{ temp_cost = 0;flag = 0;
				for (int l = 0; l < k; ++l)
				{
					if(l<=k/2)
					{
						if((v[j+l] - (l+1)) <0)
							{
								break;
								flag = 1;
							}
						temp_cost+=(v[j+l] - (l+1));
						//if(j+l !=0)
							//temp_cost+=sum[j+l-1];

					}
					else
					{
						if((v[j+l] - (j+l-2*(j+l-k/2)+1)) < 0)
							{
								break;
								flag = 1;
							}
						temp_cost += (v[j+l] - (j+l-2*(j+l-k/2)+1));
					}
				}
				if(j+k < n && flag == 0)
					temp_cost+=(sum[n-1] - sum[j+k]);
				if(j!=0 && flag == 0)
					temp_cost+=sum[j-1];

				if(temp_cost  < cost)
					{
						cost = temp_cost;
						/*if(j!=0)
							cost+=sum[j-1];//cost for making blocks left to temple as zero
						if(j+k<n)
							cost+=(sum[n-1] - sum[j+k]);//cost for making blocks right to temple as zero
						*/

					}
			}
		}


		
		printf("%d\n",cost);
		v.clear();
		sum.clear();

	}
	return 0;
}
