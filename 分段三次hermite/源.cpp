#include<iostream>

using namespace std;

/*�жϲ�ֵ�����ڵ����䣬��������������ı��*/
double judge(double *x,double x0) 
{
	/*m:������������ı��
	* t,t1:�����ж�x0���ڵ�����
	*/
	double t= fabs(x0 - x[0]) + fabs(x0 - x[1]);
	int m = 0;
	for (int i = 1; i < 6; i++) 
	{
		double t1 = fabs(x0 - x[i]) + fabs(x0 - x[i + 1]);
		if (t > t1) 
		{
			t = t1;
			m = i;
		}
	}
	return m;
}

/*���빫ʽ�������ֵ���ֵ�������ز�ֵ���ֵ*/
double Hermite(double *x, double *y,double *z, int i, double x0)
{
	/* h;��ֵ���ֵ
	t[],temp[];��Ϊ�˼򻯹�ʽ�������i��i+1������ֵ
	*/
	double h;
	double t[2]; double temp[3];
	t[0] = (x[i] - x0) / (x[i+1] - x[i]);
	t[1] = (x[i + 1] - x0) / (x[i + 1] - x[i]);

	temp[0] = x0 - x[i];
	temp[1] = x[i + 1] - x[i];
	temp[2] = x[i + 1] - x0;

	h = (1 + 2 * temp[0] / temp[1])*t[1] * t[1] * y[i] + (1 + 2 * temp[2] / temp[1])*t[0] * t[0] * y[i + 1] + temp[0] * t[1] * t[1] * z[i] - temp[2] * t[0] * t[0] * z[i + 1];
	return h;
}

int main() 
{
	/* x[]:��ֵ�ڵ� ,y[]:��ֵ�ڵ��Ӧ�ĺ���ֵ��z[]:��ֵ�ڵ��Ӧ�ĵ���ֵ��
	*/
	double x[6] = { 0.3,0.32,0.34,0.36,0.38,0.40 };
	double y[6] = { 0.295520,0.314567,0.333487,0.352274,0.370920,0.389418 };
	double z[6] = { 0.955336,0.949235,0.942755,0.935897,0.928665,0.921061 };
	double x0;
	cout << "�����������ֵ���ֵ������ֵ������Ϊ��0.3��0.4����" << endl;
	cin >> x0;
	int i;
	double t;
	
	i = judge(x, x0);
	t = Hermite(x, y, z, i, x0);
	cout << "�ֶ�Hermite��ֵ�Ľ��Ϊ��" << endl << t << endl;

	system("pause");
	return 0;
}

