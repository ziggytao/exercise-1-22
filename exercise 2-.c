#include <stdio.h>
int getbit(int x,int p,int n,int y);
int main(void)
{
	int x = 32,y = 63;
	printf("%d\n",getbit(x,3,3,y));
	return 0;
}
int getbit(int x,int p,int n,int y)
{
	return (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & ~(~0 << n)) << (p + 1 - n));
}
