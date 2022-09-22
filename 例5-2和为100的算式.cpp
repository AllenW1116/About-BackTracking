#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

//����5.4�����һ���㷨��1��2������9��˳���ܱ䣩����֮����� + �� - ��ʲô�������룬ʹ�ü���������100�ĳ��򣬲�������еĿ����ԡ�
//���磺1 + 2 + 34�C5 + 67�C8 + 9 = 100��

//�⣺�á�����a�����1��9���������á��ַ�����op����Ų�����������op[i]��ʾ��a[i]֮ǰ������������
//���û��ݷ�������Ϊ100�ı���ʽ��op[i]ֻ��ȡֵ + �� - ���߿ո񣨲�ͬ����һ��ʾ������������ѡһ������ƺ�����
//fun(op��sum��prevadd��a��i)
//���У�sum��¼��������a[i]ʱǰ�����ʽ����������ͣ���ʼֵΪa[0]����prevadd��¼ǰ�����ʽ�е�һ����ֵ����ʼֵΪa[0]��
//��i��1��ʼ��9���������sum = 100���õ�һ���⡣

const int N = 9;
void fun(char op[], int sum, int prevadd, int a[], int i)
{
	if (i == N)			  //ɨ��������λ��
	{
		if (sum == 100)		  //�ҵ�һ����
		{
			printf("  %d", a[0]);	  //�����
			for (int j = 1; j < N; j++)
			{
				if (op[j] != ' ')
					printf("%c", op[j]);
				printf("%d", a[j]);
			}
			printf("=100\n");
		}
		return;
	}
	op[i] = '+';		  //λ��i����'+'
	sum += a[i];		  //������
	fun(op, sum, a[i], a, i + 1);	  //����������һ��λ��
	sum -= a[i];		  //����



	op[i] = '-';		  //λ��i����'-'
	sum -= a[i];		  //������
	fun(op, sum, -a[i], a, i + 1);	  //����������һ��λ��
	sum += a[i];		  //����



	op[i] = ' ';		  //λ��i����' '  //����ո����˼��3 4 means 34��
	sum -= prevadd;		  //�ȼ�ȥǰ���Ԫ��ֵ  ��Ҫ��ʮλ������һ������������ �ʰ�����ȥ
	int tmp;			  //������Ԫ��ֵ
	if (prevadd > 0)
		tmp = prevadd * 10 + a[i];	  //��prevadd=5,a[i]=6,���Ϊ56
	else
		tmp = prevadd * 10 - a[i];	  //��prevadd=-5,a[i]=6,���Ϊ-56
	sum += tmp;			  //����ϲ����
	fun(op, sum, tmp, a, i + 1);	  //����������һ��λ��
	sum -= tmp;			  //����sum
	sum += prevadd;			//Ϊɶ����Ҫ��һ���µı���temp������λ����������ͳһ��prevadd�������prevadd�еĵ�λ�������ˣ���û�������ˣ�
}

void main()
{
	int a[N];
	char op[N];			//op[i]��ʾ��λ��i���������
	for (int i = 0; i < N; i++)  	//Ϊa��ֵΪ1,2��...,9
		a[i] = i + 1;
	printf("�����\n");
	fun(op, a[0], a[0], a, 1);	//����λ��i��1��ʼ;preadd��ʼΪa[0]
}

