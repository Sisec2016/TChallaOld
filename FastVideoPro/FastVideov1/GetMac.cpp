#include "GetMac.h"

void byte2Hex(unsigned char bData, unsigned char hex[])
{
	int high = bData / 16, low = bData % 16;
	hex[0] = (high < 10) ? ('0' + high) : ('A' + high - 10);
	hex[1] = (low < 10) ? ('0' + low) : ('A' + low - 10);
}

int getLocalMac(unsigned char *mac) //��ȡ����MACַ 
{
	ULONG ulSize = 0;
	PIP_ADAPTER_INFO pInfo = NULL;
	int temp = 0;
	temp = GetAdaptersInfo(pInfo, &ulSize);//��һ�����ã���ȡ��������С
	pInfo = (PIP_ADAPTER_INFO)malloc(ulSize);
	temp = GetAdaptersInfo(pInfo, &ulSize);

	int iCount = 0;
	while (pInfo)//����ÿһ������
	{
		//  pInfo->Address MACַ
		for (int i = 0; i < (int)pInfo->AddressLength; i++)
		{
			byte2Hex(pInfo->Address[i], &mac[iCount]);
			iCount += 2;
			if (i < (int)pInfo->AddressLength - 1)
			{
				//mac[iCount++] = '-';
			}
			else
			{
				mac[iCount++] = '#';
			}
		}
		pInfo = pInfo->Next;
	}

	if (iCount > 0)
	{
		mac[--iCount] = '\0';
		return iCount;
	}
	else return -1;
}

bool ReadAuthorizationFile(string &filedat)
{
	QFile file(AuthorFile);
	QString str;
	if (file.open(QIODevice::ReadOnly))//QIODevice ReadOnly
	{
		QDataStream stream(&file);
		stream >> str;
		filedat = str.toStdString();
		file.close();
	}
	else
	{
		return false;
	}

	return true;
}