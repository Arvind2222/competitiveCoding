#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	int ele;
	int k;
	int n,q;
	std::vector<int> v;
	int result;
	
	for (int i = 0; i < t; ++i)
	{
		scanf("%d %d",&n,&q);

		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&ele);
			
			v.push_back(ele);

			
		}
		sort(v.rbegin(), v.rend());

		
		
		
		for (int j = 0; j < q; ++j)
		{
			scanf("%d",&k);
			
			
						int remain;
						int pos;
						int result = 0;
			if(k>v[0]+n-1)
				{
					
					result = 0;
				}
			else if(v[n-1]>=k)
				{
					
					result = n;
					
				}
			else {


						
					int temp3 = n-1;
					
					
							while(v[temp3]<k && temp3>=0)
							{
								temp3--;
							}

						
					if(temp3 == -1)
						{
							
							pos = 0;
							remain = n;
							result = 0;
								while(k - v[pos+1] <= remain-1 && pos <= n-1 && remain > 0)
								{
									if(k-v[pos+1] <= remain-1)
									{
										pos++;
										remain -= (k-v[pos]);
											result++;

									}
								}

						}
					else
					{
						
						pos = temp3;
						
						remain = n - pos -1;
						
						result = pos + 1;
						
						while(k - v[pos+1] <= remain-1 && pos <= n-1 && remain > 0)
						{
							if(k-v[pos+1] <= remain-1)
							{
								pos++;
								remain -= (k-v[pos]);
								
								result++;
								


							}
						}

					}
					
						
						



				}
		
		printf("%d\n",result);
	}
		
		v.clear();
	}


	return 0;
}