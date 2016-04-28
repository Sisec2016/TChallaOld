#ifndef __TYPE_DEF_H
#define __TYPE_DEF_H


enum
{
	ERR_SUCCESS,
	ERR_EXIST,
	ERR_SHARE_NOT_LOGIN,//û�е�¼��������
	ERR_UNIMPORTANT,	//���������Ѿ��������ļ�����û����ȫ����
	ERR_UNKNOWN,
};
#define MAX_PATH_LEN 1024
typedef struct
{
	int iErr;	//��������ERR_SUCCESS��
	char szPath[MAX_PATH_LEN];	//�����ļ����ļ���·��
	bool bIsCover;	//�Ƿ񸲸ǣ� true ����
}T_ErrInfo;
typedef void (*pFuncMovePercentCallback)(unsigned int iHandle, unsigned int iUserData, int iCurPercent, int iTotalPercent, int iType, void *pParam);



#endif