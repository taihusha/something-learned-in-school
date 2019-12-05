int e[2];
int func1(int a)
{
	int q[3];
	int b, c=3,d;
	if (a == 0)
		return 1;
	if (a == 1)
		return 1;
	b = 1;
	c = 1;
	a -=1;
	a=b-3;
	a++;
	while (a)
	{
		d = b;
		b = c;
		c = c + d;
		a = a - 1;
	}
	return c;
}
int main()
{
	int a[2];
	int k = 12;
	int b=4;
	//func1(k);
	while (k < 3)
	{
		k=k+4;
		if(k>2){
			break;
		}
	}
	return k;
}