#include "sys_include.h"

Status_t gStatus;
SysPar_t gSysPar;
DbgPar_t gDbgPar;
QsPar_t gQsPar;
DataAvg_t gSpdLL1;
DataAvg_t gSpdLL2;
DataAvg_t gSpdLL3;
DataAvg_t gSpdLL4;

const ParInitVar_t SysPar_InitVar[MAX_SYSPAR_NUM]=
{
//��������
{0,		1,	255,		0,	0,		1},	//ɴ������
{0,		1,	255,		0,	0,		1},	//ɴ������
{1,		1,	255,		0,	0,		1},	//ɴ֧������
{2,		1,	65535,	0,	30,		1},	//ɴ֧��
{3,		2,	9000000,	0,	300000,	1},	//��Ͱ���� m
{4,		1,	65535,	0,	2000,	1},	//��Ͱ������
{5,		1,	65535,	0,	470,		1},	//��Ͱ������
{6,		1,	255,		0,	0,		1},	//���ӳ�����������
{6,		1,	255,		0,	0,		1},	//
{7,		1,	65535,	0,	0,		1},	//�����ö�����ʼ��λ0-��ʹ�øù���
{8,		1,	65535,	0,	0,		1},	//�����ö���������λ0-��ʹ�øù���
{9,		2,	9000000,	0,	0,		1},	//������Ͱ���� m
//��ɴ����
{10,		1,	65535,	0,	3500,	1},	//ɴ���ٶ�0.1rpm  
{11,		1,	65535,	0,	1300,	1},	//��ǣ���TDR  Ħ�������͵����������ٶȱ�0.1
{12,		1,	65535,	0,	200,		1},	//��ǣ���MDR  Ħ��������������֮����ٱ�0.1
{13,		1,	65535,	0,	25,		1},	//��ǣ���BDR ���������͵�������֮����ٱ�0.1
{14,		1,	65535,	0,	980,		1},	//ι��� WDR Ħ��������ǰ����֮����ٱ�0.001
{15,		1,	65535,	0,	1000,	1},	//�վ��JDR ��ȡ��Ͳ��Ħ������֮���ٱ�0.001
{16,		1,	65535,	0,	100,		1},	//��ʼ��BR����ӻ����������к������ٶȵı任�ȣ�
{17,		1,	65535,	0,	14,		1},	//�ᶯ�Ƕ�
//��������
{18,		1,	255,		0,	0,		1},	//����װ�ÿ���
{19,		1,	65535,	0,	10,		1},	//�����ٶ�
{20,		1,	255,		0,	0,		1},	//��������
//��ɴ������װ������
{21,		1,	255,		0,	0,		1},	//��ɴ����������װ���(��������)����
{22,		1,	65535,	0,	0,		1},	//�������ޱ�����ֵ
{23,		1,	65535,	0,	30,		1},	//�������ޱ�����ֵ
{24,		1,	65535,	0,	10,		1},	//����ǰ������������ֵ
{25,		1,	255,		0,	0,		1},	//������λ
//����������
{26,		1,	65535,	0,	0,		1},	//ѡ���������������
{27,		1,	65535,	0,	50,		1},	//��ʱ��������  0.01S
{28,		1,	65535,	0,	25,		1},	//�������ʱ��  0.01S
{29,		1,	65535,	0,	105,		1},	//��ʱ��������  0.01S
{30,		1,	65535,	0,	12,		1},	//�������ʱ��  0.01S
{31,		1,	65535,	0,	0,		1},	// 3��ʽ���춨ʱ��������  0.01S
{32,		1,	65535,	0,	0,		1},	// 3��ʽ����������ʱ��  0.01S
{33,		1,	65535,	0,	0,		1},	//Ln��λ�� ���ڵ����������ӳ��ȡ�ֵԽ����ӳ���Խ��
{34,		1,	65535,	0,	0,		1},	//��Ӽ����N%    ��Ӽ������N%�Ĵ�ϸ�趨
{35,		1,	65535,	0,	0,		1},	//��Ӽ����S%    ��Ӽ������S���еĴ�ϸ�趨
{36,		1,	65535,	0,	30,		1},	//��Ӽ����Scm   ��ӿؿ�����S���еĳ����趨
//������������
{37,		1,	65535,	0,	4300,	1},	//���ķ��Ƶ�� 0.01hz
{38,		1,	65535,	0,	5700,	1},	//���ķ��Ƶ�� 0.01hz
{39,		1,	65535,	0,	40,		1},	//�ᶯ�ŵ�������0.1%
{40,		1,	65535,	0,	5,		1},	//�ᶯ��������ʱ�� 1s
{41,		1,	65535,	0,	5,		1},	//�ᶯ��������ʱ��1s
{42,		1,	65535,	0,	180,		1},	//�����ʱ��1s
{43,		1,	65535,	0,	60,		1},	//��������1s
{44,		1,	65535,	0,	6,		1},	//������ʱ��1s
{45,		1,	65535,	0,	9,		1},	//�����ر�ʱ��1s
{46,		1,	65535,	0,	1,		1},	//����ѹ����ȷ��ʱ��1min
{47,		1,	65535,	0,	1,		1},	//���Źرգ��ػ��䳤�ڴ����ֶ�ģʽ����ȷ��ʱ��1min
{48,		1,	65535,	0,	20,		1},	//��·���Źر�ʱ��1s
{49,		1,	65535,	0,	35,		1},	//�ػ��ų�װ������ʱ�� 1s
{50,		1,	65535,	0,	10,		1},	//���������  min
{51,		1,	65535,	0,	178,		1},	//����ر��ӳ�s
{52,		1,	65535,	0,	5,		1},	// ���Ͳɴͣ��ʱ�䳬����Ͳɴ���ʹ�������תʱ�䣬�������VOS��Ļ�л���ʾ����
{53,		1,	65535,	0,	10,		1},	//��ѹ��ѹȷ��ʱ����ֵ
{54,		1,	65535,	0,	100,		1},	//��ѹ��ѹȷ��ʱ����ֵ
//������������
{55,		1,	255,		0,	2,		1},	//��ͷ���Դ���
{56,		1,	255,		0,	0,		1},	//����ƹ���
{56,		1,	255,		0,	0,		1},	//̽ɴʹ��
{57,		2,	65535,	0,	1950,	1},	//��װ��L1  m
{58,		2,	65535,	0,	4500,	1},	//��װ��L2  m
{59,		2,	65535,	0,	6500,	1},	//��װ��L3  m
{60,		2,	65535,	0,	13000,	1},	//��װ��L4  m
{61,		2,	65535,	0,	26000,	1},	//��װ��L5  m
{62,		2,	65535,	0,	39000,	1},	//��װ��L6  m
{63,		2,	65535,	0,	45000,	1},	//��װ��L7  m
{64,		2,	65535,	0,	58000,	1},	//��װ��L8  m
{65,		1,	65535,	0,	100,		1},	//ҡ��̧��ʱ��T1  
{66,		1,	65535,	0,	100,		1},	//ҡ��̧��ʱ��T2  
{67,		1,	65535,	0,	100,		1},	//ҡ��̧��ʱ��T3  
{68,		1,	65535,	0,	100,		1},	//ҡ��̧��ʱ��T4  
{69,		1,	65535,	0,	100,		1},	//ҡ��̧��ʱ��T5  
{70,		1,	65535,	0,	100,		1},	//ҡ��̧��ʱ��T6  
{71,		1,	65535,	0,	100,		1},	//ҡ��̧��ʱ��T7 
{72,		1,	65535,	0,	100,		1},	//ҡ��̧��ʱ��T8  
{73,		1,	65535,	0,	100,		1},	//��ͰԤ��ʱ��
//����С����������
{74,		1,	65535,	0,	24,		1},	// ��ɴ���ر���ʱ  �����ɵ��رռ�ɴ����ʱ��0.1s
{75,		1,	65535,	0,	30,		1},	// ͹����פ��ʱ��0.1s
{76,		1,	65535,	0,	60,		1},	// �ϲ�ɴ�߼����ʱ0.1s
{77,		1,	65535,	0,	10,		1},	// �²�ɴ�߼����ʱ0.1s
{78,		1,	65535,	0,	18,		1},	// Ͳ��̧����ʱ0.1s
{79,		1,	65535,	0,	0,		1},	// ��ת��������ٹ���
{80,		1,	65535,	0,	200,		1},	// ��ת�����ٶ�1
{81,		1,	65535,	0,	200,		1},	// ��ת�����ٶ�2
{82,		1,	65535,	0,	200,		1},	// ��ת�����ٶ�3
{83,		1,	65535,	0,	200,		1},	// ��ת�����ٶ�4
{84,		1,	65535,	0,	200,		1},	// ��ת�����ٶ�5
{85,		1,	65535,	0,	200,		1},	// ��ת�����ٶ�6
{86,		1,	65535,	0,	200,		1},	// ��ת�����ٶ�7
{87,		1,	65535,	0,	200,		1},	// ��ת�����ٶ�8
{88,		1,	65535,	0,	300,		1},	//��ת������תʱ��
{88,		1,	65535,	0,	300,		1},	//��ת���������ӳ�
{88,		1,	65535,	0,	300,		1},	//��ת������������ӳ�
{89,		1,	65535,	0,	0,		1},	//��������ɴʱ�䣨����L��T��LL��TT����ʱ��
{90,		1,	65535,	0,	0,		1},	//��������ɴʱ��HD
{91,		1,	65535,	0,	0,		1},	//��������ʱ��
{92,		1,	65535,	0,	0,		1},	//�������ر�ʱ��
{93,		1,	65535,	0,	0,		1},	//�������ʱ��
{94,		1,	65535,	0,	0,		1},	//С��������ն�ʱ
{95,		1,	65535,	0,	0,		1},	//С������ɴ���ն�ʱ
//��ɴС����������
{96,		1,	65535,	0,	30,		1},	// ͹����פ��ʱ��0.1s
{97,		1,	65535,	0,	120,		1},	// ��Ͳ��ɴʱ��0.01s
{98,		1,	65535,	0,	2000,	1},	// ��Ͳ��ɴ�ٶ�0.1rpm
{99,		1,	255,		0,	0,		1},	// ������ͷģʽ-- �Զ�����ģʽ 0-��ֹ 1-����
{100,	1,	65535,	0,	30,		1},	// Ͳ�ӵ��忪��ʱ��0.1s
{100,	1,	65535,	0,	0,		1},	//�ֶ�ģʽ - 0-λ��ֹͣ  1-΢��ģʽ
{100,	1,	65535,	0,	0,		1},	// 7����ʾ  0-��ǰ��ɴ����  1-Ŀ�굥��  2-͹������
{100,	1,	65535,	0,	0,		1},	// ��������ʹ��  0-�ر�  1-����
{97,		1,	65535,	0,	10,		1},	// ҡ�ܴ�ʱ�� 0.1s
{97,		1,	65535,	0,	0,		1},	//��ɴ��⴫�������ӳ� 0.01s
{97,		1,	65535,	0,	0,		1},	//��ɴ��⴫�����ر��ӳ� 0.01s
{100,	1,	65535,	0,	0,		1},	//��ɴ��⴫�����ж�ʱ�� 0.1s
{97,		1,	65535,	0,	4,		1},	//������ǰ����	
{97,		1,	65535,	0,	1,		1},	//��Ͳ��ǰ����

//ϵͳ����
{101,	1,	255,		0,	12,		1},	//�豸����	
{102,	1,	255,		0,	1,		1},	//����С������  ȡ4��λ��ÿ��λ����һ̨����С��
{103,	1,	65535,	0,	1,		1},	//����С��1��ʼ����
{104,	1,	65535,	0,	30,		1},	//����С��1��������
{105,	1,	65535,	0,	24,		1},	//����С��2��ʼ����
{106,	1,	65535,	0,	48,		1},	//����С��2��������
{107,	1,	65535,	0,	40,		1},	//����С��3��ʼ����
{108,	1,	65535,	0,	72,		1},	//����С��3��������
{109,	1,	65535,	0,	64,		1},	//����С��4��ʼ����
{110,	1,	65535,	0,	96,		1},	//����С��4��������
{111,	1,	65535,	0,	100,		1},	//����С�������ٶ�--����
{111,	1,	65535,	0,	100,		1},	//����С�������ٶ�--����
{111,	1,	65535,	0,	100,		1},	//����С�������ٶ�--����
{111,	1,	65535,	0,	100,		1},	//����С��͹���ٶ�
{111,	1,	65535,	0,	100,		1},	//����С��������ٶ�
{112,	1,	65535,	0,	0,		1},	//����������Ƭ覴õ��С��������ʱ����������λ��
{113,	1,	65535,	0,	0,		1},	//��Ӽ��������
{114,	1,	65535,	0,	1,		1},	//��ɴС��1��ʼ����
{115,	1,	65535,	0,	96,		1},	//��ɴС��1��������
{116,	1,	65535,	0,	0,		1},	//����װ����תģʽ
{117,	1,	65535,	0,	0,		1},	//�չܲ���ģʽ--- �򹩹�װ���ƶ�ģʽ 0-ɴ���ϲ�ȴ�� 1-ɴ��ȱ��
{118,	1,	65535,	0,	45,		1},	//��ɴС�������ٶ�
{119,	1,	65535,	0,	15,		1},	//��ɴС�������ٶ�
{120,	1,	65535,	0,	8,		1},	//��ɴС�������ٶ�
{121,	1,	255,		0,	0,		1},	//������������� �Զ�/�ֶ�
{122,	1,	255,		0,	0,		1},	//������������� �Զ�/�ֶ�
//���������������趨
{123,	1,	65535,	0,	0,		1},	//�����ھ��ȶ�ǿ��ֹͣ
{124,	1,	65535,	0,	0,		1},	//CV���ȶ�ǿ��ֹͣ
{125,	1,	65535,	0,	0,		1},	//HD �෢ǿ��ֹͣ
{126,	1,	65535,	0,	0,		1},	//HD �෢��ֵ
{127,	1,	65535,	0,	0,		1},	//��ɴǿ��ֹͣ
{128,	1,	65535,	0,	10,		1},	//��ɴ�෢ʱ����ֵ
{129,	1,	65535,	0,	10,		1},	//��ɴ�෢��������
{130,	1,	65535,	0,	0,		1},	//��������ֹͣ
{131,	1,	65535,	0,	1,		1},	//��������ʱ��
{132,	1,	65535,	0,	5,		1},	//ǿ��ֹͣ���ʱ��
{133,	1,	65535,	0,	0,		1},	//�쳣���ʱ����ģʽ
{134,	1,	65535,	0,	0,		1},	//������׼ֵ����ǿ��ֹͣ
{135,	1,	65535,	0,	10,		1},	//������׼ֵ�����
{136,	1,	65535,	0,	30,		1},	//���ٱ�������1	
{137,	1,	65535,	0,	30,		1},	//���ٱ�������2
{138,	1,	65535,	0,	30,		1},	//���ٱ�������3
{139,	1,	65535,	0,	30,		1},	//���ٱ�������4
{140,	1,	65535,	0,	0,		1},	//�����ѹ������
{141,	1,	65535,	0,	0,		1},	//�����ѹ������
{142,	1,	65535,	0,	0,		1},	//�����ѹ����������
{143,	1,	65535,	0,	0,		1},	//�����ѹ������
{144,	1,	65535,	0,	0,		1},	//�����ѹ������
{145,	1,	65535,	0,	0,		1},	//�����ѹ����������


};

const ParInitVar_t QsPar_InitVar[MAX_QSPAR_NUM]=
{
//
{0,	1,	255,		0,	0,		1},	//	ɴ���ٶ�
{1,	1,	255,		0,	0,		1},	//	ɴ�ߺ���
{2,	1,	65535,	0,	0,		1},	//��ͷ��������
{3,	1,	65535,	0,	0,		1},	//����ֱ��+����
{4,	1,	65535,	0,	0,		1},	//ϸ��ֱ��+����
{5,	1,	65535,	0,	0,		1},	//SL1ֱ��D1+����L1
{6,	1,	65535,	0,	0,		1},	//SL2ֱ��D2+����L2
{7,	1,	65535,	0,	0,		1},	//SL3ֱ��D3+����L3
{8,	1,	65535,	0,	0,		1},	//SL4ֱ��D4+����L4
{9,	1,	65535,	0,	0,		1},	//SL5ֱ��D5+����L5
{10,	1,	65535,	0,	0,		1},	//HDdֱ��D6+����L6
{11,	1,	65535,	0,	0,		1},	//TL1ֱ��D7+����L7
{12,	1,	65535,	0,	0,		1},	//TL2ֱ��D8+����L8
{13,	1,	65535,	0,	0,		1},	//TL3ֱ��D9+����L9
{14,	1,	255,		0,	0,		1},	//��״ɴ��ֱ��
{15,	1,	255,		0,	0,		1},	//��״����mm
{16,	1,	255,		0,	0,		1},	//��״ɴ�ø���
{17,	1,	255,		0,	0,		1},	//��ⳤ��cm
{18,	1,	255,		0,	0,		1},	//��ɴ������
{19,	1,	255,		0,	0,		1},	//	
};

const ParInitVar_t DbgPar_InitVar[MAX_DBGPAR_NUM]=
{
//
{0,	1,	255,		0,	0,		1},	// ���1_T1
{1,	1,	255,		0,	0,		1},	// ���1_T2
{2,	1,	255,		0,	0,		1},	// ���1_T3
{3,	1,	255,		0,	0,		1},	// ���1_T4
{4,	1,	255,		0,	0,		1},	// ���1_T5
{5,	1,	255,		0,	0,		1},	//���1_T6
{6,	1,	255,		0,	0,		1},	//���1_T7
{7,	1,	255,		0,	0,		1},	//���1_T8
{8,	1,	255,		0,	0,		1},	//���1_T9
{9,	1,	255,		0,	0,		1},	// ���1_T10
{10,	1,	255,		0,	0,		1},	// ���1_T11
{11,	1,	255,		0,	0,		1},	//�ȴ�_T1
{12,	1,	255,		0,	0,		1},	// �ȴ�_T2
{13,	1,	255,		0,	0,		1},	//�ȴ�_T3
{14,	1,	255,		0,	0,		1},	//���2_T1
{15,	1,	255,		0,	0,		1},	//���2_T2
{16,	1,	255,		0,	0,		1},	 //���2_T3
{17,	1,	255,		0,	0,		1},	//���2_T4
{18,	1,	255,		0,	0,		1},	//���2_T5
{19,	1,	255,		0,	0,		1},	//���2_T6
{20,	1,	255,		0,	0,		1},	// ���_T1
{21,	1,	255,		0,	0,		1},	//���_T2
{22,	1,	255,		0,	0,		1},	//���_T3
{23,	1,	255,		0,	0,		1},	//���_T4
{24,	1,	255,		0,	0,		1},	//���_T5
{25,	1,	255,		0,	0,		1},	//���_T6
{26,	1,	255,		0,	0,		1},	//���_T7
{27,	1,	255,		0,	0,		1},	//���_T8

//��β
{28,	1,	65535,	0,	0,		1},	//
{29,	1,	65535,	0,	0,		1},	//
{30,	1,	65535,	0,	0,		1},	//
{31,	1,	65535,	0,	0,		1},	//
{32,	1,	65535,	0,	0,		1},	//
{33,	1,	65535,	0,	0,		1},	//
{34,	1,	65535,	0,	0,		1},	//
};

const u8 auchCRCHi[] = {
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40 
}; 

const u8 auchCRCLo[] = {
 0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 
 0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD, 
 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09, 
 0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 
 0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4, 
 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3, 
 0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 
 0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4, 
 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 
 0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 
 0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED, 
 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26, 
 0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 
 0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67, 
 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 
 0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 
 0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 
 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5, 
 0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 
 0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92, 
 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C, 
 0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 
 0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B, 
 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C, 
 0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 
 0x43, 0x83, 0x41, 0x81, 0x80, 0x40 
};

u16 check_crc16(u8 *puchMsg, u16 usDataLen) 
{   
/* CRC��λ�ֽ�ֵ��*/ 
  
	u8 uchCRCHi = 0xFF ; /* ��CRC�ֽڳ�ʼ�� */ 
	u8 uchCRCLo = 0xFF ; /* ��CRC �ֽڳ�ʼ�� */ 
	u16 uIndex ; /* CRCѭ���е����� */ 
	while (usDataLen--) /* ������Ϣ������ */ 
	{ 
		uIndex = uchCRCHi ^ *puchMsg++ ; /* ����CRC */ 
		uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex] ; 
		uchCRCLo = auchCRCLo[uIndex] ; 
	} 
	return (uchCRCHi << 8 | uchCRCLo) ; 
}

u16 sum_check(u8 * dpin,u16 len)
{
	u16 i=0,sum=0;
	for(i=0;i<len;i++)
	{
		sum += *(dpin+i);
	}
	return sum;

}

void data_avg_init(DataAvg_t *dp)
{
	memset(dp,0,sizeof(DataAvg_t));
}
/***************************************************************************************/

/***************************************************************************************/
void data_avg_macro(DataAvg_t *dp)
{
	if(dp->pLen > (AVG_BUF_LEN_MAX-2)){dp->pLen = (AVG_BUF_LEN_MAX-2);}//���ȱ���
	if(dp->pLen == 0) dp->pLen = 1;
	if(dp->Index >= AVG_BUF_LEN_MAX){dp->Index = 0;}//��ֹ���������δ֪��ַ
	dp->data[dp->Index] = dp->In;//�������Ƚ��������
	dp->add += dp->In;
	dp->Index++;
	if(dp->Index >= (dp->pLen+1)){dp->Index = 0;}	
	dp->add -= dp->data[dp->Index];
	dp->Out = dp->add/dp->pLen;
}
/***************************************************************************************/



void fill_data_flash(u8 type, u8 idx_s, u8 idx_e,u8 idx_s2, u8 idx_e2)
{
	if(type == DAT_DJ)
	{
		gCanBusCtl1.TxMsg.Data[0] = idx_s;
		gCanBusCtl1.TxMsg.Data[1] = idx_e;
		gCanBusCtl1.TxMsg.Data[2] = idx_s2;
		gCanBusCtl1.TxMsg.Data[3] = idx_e2;
		gCanBusCtl1.TxMsg.Data[4] = 0;
		gCanBusCtl1.TxMsg.Data[5] = 0;
		gCanBusCtl1.TxMsg.Data[6] = (gSysCtlVal.CVAvg) & 0xff;
		gCanBusCtl1.TxMsg.Data[7] = gCanBusCtl1.CurID;//gSysCtlVal.Sts;
		gCanBusCtl1.TxMsg.DLC  = 8;
		
	}	
	else if(type == DAT_JW)
	{
		gCanBusCtl1.TxMsg.Data[0] = idx_s;
		gCanBusCtl1.TxMsg.Data[1] = idx_e;
		gCanBusCtl1.TxMsg.Data[2] = 0;
		gCanBusCtl1.TxMsg.Data[3] = 0;
		gCanBusCtl1.TxMsg.Data[4] = 0;
		gCanBusCtl1.TxMsg.Data[5] = 0;
		gCanBusCtl1.TxMsg.Data[7] = gCanBusCtl1.CurID;//gSysCtlVal.Sts;
		gCanBusCtl1.TxMsg.DLC  = 8;

	}
	else if(type == DAT_JN)
	{
		gCanBusCtl2.TxMsg.Data[0] = idx_s;
		gCanBusCtl2.TxMsg.Data[1] = idx_e;
		gCanBusCtl1.TxMsg.Data[2] = gStatus.JN[0].PosCur;
		gCanBusCtl1.TxMsg.Data[3] = gStatus.JN[1].PosCur;
		gCanBusCtl1.TxMsg.Data[4] = gStatus.JN[2].PosCur;
		gCanBusCtl1.TxMsg.Data[5] = gStatus.JN[3].PosCur;
		gCanBusCtl1.TxMsg.Data[6] = 0;
		gCanBusCtl2.TxMsg.Data[7] = gCanBusCtl2.CurID;//gSysCtlVal.Sts;
		gCanBusCtl2.TxMsg.DLC  = 8;

	}
	else if(type == DAT_AD)
	{
		gCanBusCtl2.TxMsg.Data[0] = idx_s;
		gCanBusCtl2.TxMsg.Data[1] = idx_e;
		gCanBusCtl2.TxMsg.Data[2] = 0;
		gCanBusCtl2.TxMsg.Data[3] = 0;
		gCanBusCtl2.TxMsg.Data[4] = 0;
		gCanBusCtl2.TxMsg.Data[5] = 0;
		gCanBusCtl2.TxMsg.Data[7] = gCanBusCtl2.CurID;//gSysCtlVal.Sts;
		gCanBusCtl2.TxMsg.DLC  = 8;

	}

}


void fill_data_set(u8 type, u8 idx)
{
	if(type == DAT_DJ)
	{
		if(idx == 0)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.MT_Len>>24;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.MT_Len>>16;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.MT_Len>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.MT_Len & 0xff;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.SL_En;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DZ_ContinueGQ;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.TEN_En;
			gCanBusCtl1.TxMsg.Data[7] = 0;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.BDR>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.BDR & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = 0;
			gCanBusCtl1.TxMsg.Data[3] = 0;
			gCanBusCtl1.TxMsg.Data[4] = (gSysPar.MDR>>8) & 0xff; 
			gCanBusCtl1.TxMsg.Data[5] =gSysPar.MDR & 0xff;
			gCanBusCtl1.TxMsg.Data[6] = (gSysPar.TDR>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.TDR & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 2)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.JDR>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.JDR & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gSysPar.WDR>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] =gSysPar.WDR & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =(gSysPar.BR>>8) & 0xff; 
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.BR & 0xff;
			gCanBusCtl1.TxMsg.Data[6] = 0;
			gCanBusCtl1.TxMsg.Data[7] = 0;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 3)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.XSPD >>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.XSPD & 0xff;
			gCanBusCtl1.TxMsg.Data[2] =0;
			gCanBusCtl1.TxMsg.Data[3] =0;
			gCanBusCtl1.TxMsg.Data[4] =0;
			gCanBusCtl1.TxMsg.Data[5] =0;
			gCanBusCtl1.TxMsg.Data[6] =0;
			gCanBusCtl1.TxMsg.Data[7] =0;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 4)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.TEN_HThd>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.TEN_HThd & 0xff;
			gCanBusCtl1.TxMsg.Data[2] =(gSysPar.TEN_LThd>>8) & 0xff; 
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.TEN_LThd & 0xff;
			gCanBusCtl1.TxMsg.Data[4] = (gSysPar.TEN_BDThd>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.TEN_BDThd & 0xff;
			gCanBusCtl1.TxMsg.Data[6] = (gSysPar.TEN_Reset>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.TEN_Reset & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 5)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.STOP_SL;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.STOP_SL_TimeThd;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_TSEn;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.STOP_DS; 
			gCanBusCtl1.TxMsg.Data[4] = (gSysPar.STOP_DS_TimeThd>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.STOP_DS_TimeThd & 0xff;
			gCanBusCtl1.TxMsg.Data[6] = (gSysPar.STOP_DS_CntThd>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.STOP_DS_CntThd & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 6)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.SL_Spd>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.SL_Spd & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.SL_Dir;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_JTTryN;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_RedCtl;
			gCanBusCtl1.TxMsg.Data[5] = 0;
			gCanBusCtl1.TxMsg.Data[6] = 0;
			gCanBusCtl1.TxMsg.Data[7] = 0;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 7)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.DY_Len>>24) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = (gSysPar.DY_Len>>16) & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gSysPar.DY_Len>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DY_Len & 0xff;
			gCanBusCtl1.TxMsg.Data[4] = gSysCtlVal.DY_En & 0xff;;  
			gCanBusCtl1.TxMsg.DLC  = 5;
		}
		else if(idx == 8)
		{
			gCanBusCtl1.TxMsg.Data[0] = gDbgPar.DD_QJ1_T1;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.DD_QJ1_T2;
			gCanBusCtl1.TxMsg.Data[2] = gDbgPar.DD_QJ1_T3;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.DD_QJ1_T4;
			gCanBusCtl1.TxMsg.Data[4] = gDbgPar.DD_QJ1_T5;
			gCanBusCtl1.TxMsg.Data[5] = gDbgPar.DD_QJ1_T6;
			gCanBusCtl1.TxMsg.Data[6] = gDbgPar.DD_QJ1_T7;
			gCanBusCtl1.TxMsg.Data[7] = gDbgPar.DD_QJ1_T8;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 9)
		{
			gCanBusCtl1.TxMsg.Data[0] = gDbgPar.DD_QJ1_T9;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.DD_QJ1_T10;
			gCanBusCtl1.TxMsg.Data[2] = gDbgPar.DD_QJ1_T11;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.DD_WT_T1;
			gCanBusCtl1.TxMsg.Data[4] = gDbgPar.DD_WT_T2;
			gCanBusCtl1.TxMsg.Data[5] = gDbgPar.DD_WT_T3;
			gCanBusCtl1.TxMsg.Data[6] = gDbgPar.DD_QJ2_T1;
			gCanBusCtl1.TxMsg.Data[7] = gDbgPar.DD_QJ2_T2;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 10)
		{
			gCanBusCtl1.TxMsg.Data[0] = gDbgPar.DD_QJ2_T3;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.DD_QJ2_T4;
			gCanBusCtl1.TxMsg.Data[2] = gDbgPar.DD_QJ2_T5;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.DD_QJ2_T6;
			gCanBusCtl1.TxMsg.Data[4] = gDbgPar.DD_NJ_T1;
			gCanBusCtl1.TxMsg.Data[5] = gDbgPar.DD_NJ_T2;
			gCanBusCtl1.TxMsg.Data[6] = gDbgPar.DD_NJ_T3;
			gCanBusCtl1.TxMsg.Data[7] = gDbgPar.DD_NJ_T4;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 11)
		{
			gCanBusCtl1.TxMsg.Data[0] = gDbgPar.DD_NJ_T5;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.DD_NJ_T6;
			gCanBusCtl1.TxMsg.Data[2] = gDbgPar.DD_NJ_T7;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.DD_NJ_T8;
			gCanBusCtl1.TxMsg.DLC  = 4;
		}
		else if(idx == 12)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_L1>>24;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_L1>>16;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_L1>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_L1 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_L2>>24;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_L2>>16;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_L2>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_L2 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 13)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_L3>>24;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_L3>>16;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_L3>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_L3 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_L4>>24;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_L4>>16;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_L4>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_L4 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 14)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_L5>>24;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_L5>>16;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_L5>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_L5 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_L6>>24;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_L6>>16;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_L6>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_L6 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 15)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_L7>>24;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_L7>>16;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_L7>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_L7 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_L8>>24;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_L8>>16;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_L8>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_L8 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 16)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_T1>>8;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_T1 & 0xFF;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_T2>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_T2 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_T3>>8;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_T3 & 0xFF;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_T4>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_T4 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 17)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_T5>>8;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_T5 & 0xFF;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_T6>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_T6 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_T7>>8;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_T7 & 0xFF;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_T8>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_T8 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else
		{
			gCanBusCtl1.TxMsg.Data[0] = gCanBusCtl1.CurID;
			gCanBusCtl1.TxMsg.Data[1] = gCanBusCtl1.CurCmd;
			gCanBusCtl1.TxMsg.DLC  = 2;
		}

	}
	else if(type == DAT_JW)
	{
		if(idx == 0)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gDbgPar.JW_P01>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.JW_P01 & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gDbgPar.JW_P02>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.JW_P02 & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =  (gDbgPar.JW_P03>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gDbgPar.JW_P03 & 0xff;
			gCanBusCtl1.TxMsg.Data[6] =  (gDbgPar.JW_P04>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gDbgPar.JW_P04 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gDbgPar.JW_P05>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.JW_P05 & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gDbgPar.JW_P06>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.JW_P06 & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =  (gDbgPar.JW_P07>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gDbgPar.JW_P07 & 0xff;
			gCanBusCtl1.TxMsg.Data[6] =  (gDbgPar.JW_P08>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gDbgPar.JW_P08 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else
		{
			gCanBusCtl1.TxMsg.Data[0] = gCanBusCtl1.CurID;
			gCanBusCtl1.TxMsg.Data[1] = gCanBusCtl1.CurCmd;
			gCanBusCtl1.TxMsg.DLC  = 2;
		}

	}
	else if(type == DAT_QS)
	{
		if(idx == 0)
		{
			gCanBusCtl1.TxMsg.Data[0] = gQsPar.P01_0;
			gCanBusCtl1.TxMsg.Data[1] = gQsPar.P01_1;
			gCanBusCtl1.TxMsg.Data[2] = (gQsPar.P02>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gQsPar.P02 & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =  (gQsPar.P03>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gQsPar.P03 & 0xff;
			gCanBusCtl1.TxMsg.Data[6] =  (gQsPar.P04>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gQsPar.P04 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gQsPar.P11>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gQsPar.P11 & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gQsPar.P12>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gQsPar.P12 & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =  (gQsPar.P13>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gQsPar.P13 & 0xff;
			gCanBusCtl1.TxMsg.Data[6] =  (gQsPar.P14>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gQsPar.P14 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 2)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gQsPar.P21>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gQsPar.P21 & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gQsPar.P22>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gQsPar.P22 & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =  (gQsPar.P23>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gQsPar.P23 & 0xff;
			gCanBusCtl1.TxMsg.Data[6] =  (gQsPar.P24>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gQsPar.P24 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 3)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gQsPar.P31>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gQsPar.P31 & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = gQsPar.P32_0;
			gCanBusCtl1.TxMsg.Data[3] = gQsPar.P32_1;
			gCanBusCtl1.TxMsg.Data[4] = gQsPar.P33_0;
			gCanBusCtl1.TxMsg.Data[5] =  gQsPar.P33_1;
			gCanBusCtl1.TxMsg.Data[6] = gQsPar.P34_0;
			gCanBusCtl1.TxMsg.Data[7] = gQsPar.P34_1;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else
		{
			gCanBusCtl1.TxMsg.Data[0] = gCanBusCtl1.CurID;
			gCanBusCtl1.TxMsg.Data[1] = gCanBusCtl1.CurCmd;
			gCanBusCtl1.TxMsg.DLC  = 2;
		}

	}
	else if(type == DAT_JN)
	{
		if(idx == 0)
		{
			gCanBusCtl2.TxMsg.Data[0] =  (gSysPar.JNC_JSQ_CloseDlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_JSQ_CloseDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_TL_StayTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_TL_StayTime & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_SBS_CheckDlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_SBS_CheckDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_XBS_CheckDlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_XBS_CheckDlyTime & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_ST_UpDlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_ST_UpDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_LL_SpdCtl>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_LL_SpdCtl & 0xff;
			gCanBusCtl2.TxMsg.Data[4] = (gSysPar.JNC_LL_StartDlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_LL_StartDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_LL_QGOut_DlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_LL_QGOut_DlyTime & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 2)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_LL_F1>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_LL_F1 & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_LL_F2>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_LL_F2 & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_LL_F3>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_LL_F3 & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_LL_F4>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_LL_F4 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 3)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_LL_F5>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_LL_F5 & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_LL_F6>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_LL_F6 & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_LL_F7>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_LL_F7 & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_LL_F8>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_LL_F8 & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 4)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_LL_FwdTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_LL_FwdTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_DXZ_XiShaTimeLT>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_DXZ_XiShaTimeLT & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_DXZ_XiShaTimeHD>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_DXZ_XiShaTimeHD & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_SLQJ_OpenTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_SLQJ_OpenTime & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 5)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_SLQJ_ColseTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_SLQJ_ColseTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_SLQJ_Time>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_SLQJ_Time & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_XXZ_JiaNianTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_XXZ_JiaNianTime & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_XXZ_XiShaTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_XXZ_XiShaTime & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 6)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_SpdH>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_SpdH & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_DXZ_WaitPos>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_DXZ_WaitPos & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_JNJGQ>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_JNJGQ & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = (gSysPar.JNC_SpdM>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_SpdM & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 7)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_SpdL>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_SpdL & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_TL_Spd>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_TL_Spd & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_DJ_Spd>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_DJ_Spd & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = (gSysPar.JN_LnPos>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JN_LnPos & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 8)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JN_JiaNianStartTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JN_JiaNianStartTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JN_JiaNianTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JN_JiaNianTime & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JN_JieNianStartTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JN_JieNianStartTime & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = (gSysPar.JN_JieNianTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JN_JieNianTime & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 9)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.DD_L1>>24;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.DD_L1>>16;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.DD_L1>>8;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.DD_L1 & 0xFF;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.DD_L2>>24;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.DD_L2>>16;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.DD_L2>>8;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.DD_L2 & 0xFF;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 10)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.DD_L3>>24;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.DD_L3>>16;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.DD_L3>>8;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.DD_L3 & 0xFF;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.DD_L4>>24;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.DD_L4>>16;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.DD_L4>>8;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.DD_L4 & 0xFF;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 11)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.DD_L5>>24;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.DD_L5>>16;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.DD_L5>>8;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.DD_L5 & 0xFF;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.DD_L6>>24;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.DD_L6>>16;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.DD_L6>>8;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.DD_L6 & 0xFF;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 12)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.DD_L7>>24;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.DD_L7>>16;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.DD_L7>>8;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.DD_L7 & 0xFF;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.DD_L8>>24;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.DD_L8>>16;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.DD_L8>>8;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.DD_L8 & 0xFF;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}		
		else if(idx == 13)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.JNC_S[0]& 0xFF;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_E[0]& 0xFF;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.JNC_S[1]& 0xFF;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_E[1]& 0xFF;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.JNC_S[2]& 0xFF;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_E[2]& 0xFF;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.JNC_S[3]& 0xFF;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_E[3]& 0xFF;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}				
		else
		{
			gCanBusCtl2.TxMsg.Data[0] = gCanBusCtl2.CurID;
			gCanBusCtl2.TxMsg.Data[1] = gCanBusCtl2.CurCmd;
			gCanBusCtl2.TxMsg.DLC  = 2;
		}
	}
	else if(type == DAT_QS1)
	{
		if(idx == 0)
		{
			gCanBusCtl2.TxMsg.Data[0] = gQsPar.P01_0;
			gCanBusCtl2.TxMsg.Data[1] = gQsPar.P01_1;
			gCanBusCtl2.TxMsg.Data[2] = (gQsPar.P02>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gQsPar.P02 & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gQsPar.P03>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gQsPar.P03 & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gQsPar.P04>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gQsPar.P04 & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gQsPar.P11>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gQsPar.P11 & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gQsPar.P12>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gQsPar.P12 & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gQsPar.P13>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gQsPar.P13 & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gQsPar.P14>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gQsPar.P14 & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 2)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gQsPar.P21>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gQsPar.P21 & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gQsPar.P22>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gQsPar.P22 & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gQsPar.P23>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gQsPar.P23 & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gQsPar.P24>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gQsPar.P24 & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 3)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gQsPar.P31>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gQsPar.P31 & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = gQsPar.P32_0;
			gCanBusCtl2.TxMsg.Data[3] = gQsPar.P32_1;
			gCanBusCtl2.TxMsg.Data[4] = gQsPar.P33_0;
			gCanBusCtl2.TxMsg.Data[5] =  gQsPar.P33_1;
			gCanBusCtl2.TxMsg.Data[6] = gQsPar.P34_0;
			gCanBusCtl2.TxMsg.Data[7] = gQsPar.P34_1;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else
		{
			gCanBusCtl2.TxMsg.Data[0] = gCanBusCtl2.CurID;
			gCanBusCtl2.TxMsg.Data[1] = gCanBusCtl2.CurCmd;
			gCanBusCtl2.TxMsg.DLC  = 2;
		}

	}	
	else if(type == DAT_AD)
	{
		if(idx == 0)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.LSC_HSpd & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.LSC_MSpd & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.LSC_LSpd & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.LSC_TL_StayTime & 0xff;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.LSC_ST_Mode & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.LSC_Manual_Mode & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.LSC_GGDEV_EmptyFillMode & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.LSC_SLQJ_EN & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.LSC_Display_7 & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.LSC_RTJS_Time & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.LSC_RTJS_Spd>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] =  gSysPar.LSC_RTJS_Spd & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.LSC_DB_OpenTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] =  gSysPar.LSC_DB_OpenTime & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.LSC_S1 & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.LSC_E1 & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 2)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.LSC_YJ_OpenTime & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.LSC_YARN_OpenDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.LSC_YARN_CloseDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.LSC_YARN_CheckTime & 0xff;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.LSC_TQJS_BY & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.LSC_TQJS_LT & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = 0;
			gCanBusCtl2.TxMsg.Data[7] = 0;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 3)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.LSC_LSpd>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.LSC_LSpd & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = 0;
			gCanBusCtl2.TxMsg.Data[3] = 0;
			gCanBusCtl2.TxMsg.Data[4] = 0;
			gCanBusCtl2.TxMsg.Data[5] = 0;
			gCanBusCtl2.TxMsg.Data[6] = 0;
			gCanBusCtl2.TxMsg.Data[7] = 0;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else
		{
			gCanBusCtl2.TxMsg.Data[0] = gCanBusCtl2.CurID;
			gCanBusCtl2.TxMsg.Data[1] = gCanBusCtl2.CurCmd;
			gCanBusCtl2.TxMsg.DLC  = 2;
		}
	}

}



void data_upate_status(void)
{
	gStatus.JT.RunSts = gSysCtlVal.Sts;

	//�����ѹ
	gStatus.JT.NP_MFan = gStatus.JW[0].Ang1;
	gStatus.JT.NP_MFan = gStatus.JW[0].Ang2;


	//�����ٶȷ���
	gSpdLL1.pLen = 20;//	200ms
	gSpdLL1.In =  gSysHard.Spd1;
	data_avg_macro(&gSpdLL1);
	gStatus.JT.SpdFk_LL1 = gSpdLL1.Out;
	gSpdLL2.pLen = 20;//	200ms
	gSpdLL2.In =  gSysHard.Spd2;
	data_avg_macro(&gSpdLL2);
	gStatus.JT.SpdFk_LL2 = gSpdLL2.Out;	
	gSpdLL3.pLen = 20;//	200ms
	gSpdLL3.In =  gSysHard.Spd3;
	data_avg_macro(&gSpdLL3);
	gStatus.JT.SpdFk_LL3 = gSpdLL3.Out;	
	gSpdLL4.pLen = 20;//	200ms
	gSpdLL4.In =  gSysHard.Spd4;
	data_avg_macro(&gSpdLL4);
	gStatus.JT.SpdFk_LL4 = gSpdLL4.Out;	


	//��Ƶ��״̬
	gStatus.JT.VFD1.Dat1 = gVfdCom.Mxx[0].oFre_hz;
	gStatus.JT.VFD1.Dat2 = gVfdCom.Mxx[0].oCur;
	gStatus.JT.VFD1.Dat3 = gVfdCom.Mxx[0].oVol;
	gStatus.JT.VFD1.Dat4 = gVfdCom.Mxx[0].oP;
	gStatus.JT.VFD1.Dat5 = 0;
	gStatus.JT.VFD2.Dat1 = gVfdCom.Mxx[1].oFre_hz;
	gStatus.JT.VFD2.Dat2 = gVfdCom.Mxx[1].oCur;
	gStatus.JT.VFD2.Dat3 = gVfdCom.Mxx[1].oVol;
	gStatus.JT.VFD2.Dat4 = gVfdCom.Mxx[1].oP;
	gStatus.JT.VFD2.Dat5 = 0;
	gStatus.JT.VFD3.Dat1 = gVfdCom.Mxx[2].oFre_hz;
	gStatus.JT.VFD3.Dat2 = gVfdCom.Mxx[2].oCur;
	gStatus.JT.VFD3.Dat3 = gVfdCom.Mxx[2].oVol;
	gStatus.JT.VFD3.Dat4 = gVfdCom.Mxx[2].oP;
	gStatus.JT.VFD3.Dat5 = 0;
	gStatus.JT.VFD4.Dat1 = gVfdCom.Mxx[3].oFre_hz;
	gStatus.JT.VFD4.Dat2 = gVfdCom.Mxx[3].oCur;
	gStatus.JT.VFD4.Dat3 = gVfdCom.Mxx[3].oVol;
	gStatus.JT.VFD4.Dat4 = gVfdCom.Mxx[3].oP;
	gStatus.JT.VFD4.Dat5 = 0;
	gStatus.JT.VFD5.Dat1 = gVfdCom.Mxx[4].oFre_hz;
	gStatus.JT.VFD5.Dat2 = gVfdCom.Mxx[4].oCur;
	gStatus.JT.VFD5.Dat3 = gVfdCom.Mxx[4].oVol;
	gStatus.JT.VFD5.Dat4 = gVfdCom.Mxx[4].oP;
	gStatus.JT.VFD5.Dat5 = 0;
	gStatus.JT.VFD6.Dat1 = gVfdCom.Mxx[5].oFre_hz;
	gStatus.JT.VFD6.Dat2 = gVfdCom.Mxx[5].oCur;
	gStatus.JT.VFD6.Dat3 = gVfdCom.Mxx[5].oVol;
	gStatus.JT.VFD6.Dat4 = gVfdCom.Mxx[5].oP;
	gStatus.JT.VFD6.Dat5 = 0;
	gStatus.JT.VFD7.Dat1 = gVfdCom.Mxx[6].oFre_hz;
	gStatus.JT.VFD7.Dat2 = gVfdCom.Mxx[6].oCur;
	gStatus.JT.VFD7.Dat3 = gVfdCom.Mxx[6].oVol;
	gStatus.JT.VFD7.Dat4 = gVfdCom.Mxx[6].oP;
	gStatus.JT.VFD7.Dat5 = 0;

	gStatus.JT.ERR1 = gSysHard.VfdErr.All & 0x7F;
}

void sys_par_init(u8 type, u16* pbf)
{	
	u16 i=0;
	u16 num = 0;

	if(type == 0)
	{
		while(num < MAX_SYSPAR_NUM)
		{
			if(SysPar_InitVar[num].Size == 1)
			{
				if(SysPar_InitVar[num].RstFlag)
					*(pbf+i) = SysPar_InitVar[num].Default;
				i++;
			}
			else if(SysPar_InitVar[num].Size == 2)
			{	
				
				if(SysPar_InitVar[num].RstFlag)
					*(pbf+i) = SysPar_InitVar[num].Default&0xFFFF;
				i++;
				
				if(SysPar_InitVar[num].RstFlag)
					*(pbf+i) = SysPar_InitVar[num].Default>>16;
				i++;
			}
				
			num++;
		}
	}
	else if(type == 1)
	{
		while(num < MAX_QSPAR_NUM)
		{
			if(QsPar_InitVar[num].Size == 1)
			{
				if(QsPar_InitVar[num].RstFlag)
					*(pbf+i) = QsPar_InitVar[num].Default;
				i++;
			}
			else if(QsPar_InitVar[num].Size == 2)
			{	
				
				if(QsPar_InitVar[num].RstFlag)
					*(pbf+i) = QsPar_InitVar[num].Default&0xFFFF;
				i++;
				
				if(QsPar_InitVar[num].RstFlag)
					*(pbf+i) = QsPar_InitVar[num].Default>>16;
				i++;
			}
				
			num++;
		}
	}
	else if(type == 2)
	{
		while(num < MAX_DBGPAR_NUM)
		{
			if(DbgPar_InitVar[num].Size == 1)
			{
				if(DbgPar_InitVar[num].RstFlag)
					*(pbf+i) = DbgPar_InitVar[num].Default;
				i++;
			}
			else if(DbgPar_InitVar[num].Size == 2)
			{	
				
				if(DbgPar_InitVar[num].RstFlag)
					*(pbf+i) = DbgPar_InitVar[num].Default&0xFFFF;
				i++;
				
				if(DbgPar_InitVar[num].RstFlag)
					*(pbf+i) = DbgPar_InitVar[num].Default>>16;
				i++;
			}
				
			num++;
		}
	}
	
}

void data_init(void)
{

	memset(&gSysPar, 0, sizeof(SysPar_t));
	memset(&gQsPar, 0, sizeof(QsPar_t));
	memset(&gDbgPar, 0, sizeof(DbgPar_t));

	sys_par_init(0, (u16*)&gSysPar);
	
	data_avg_init(&gSpdLL1);
	data_avg_init(&gSpdLL2);
	data_avg_init(&gSpdLL3);
	data_avg_init(&gSpdLL4);



}
