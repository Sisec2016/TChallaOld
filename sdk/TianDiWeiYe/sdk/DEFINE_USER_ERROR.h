#ifndef _DEFINE_USER_ERROR_H
#define _DEFINE_USER_ERROR_H

//�ṩ���û�����ϸ����˵��
#define USER_ERROR  0x10000000
#define ERROR_NO_DEV			USER_ERROR+1    //û���ҵ��豸
#define ERROR_UNLOGON			USER_ERROR+2    //δ��¼
#define ERROR_PARAM_OVER		USER_ERROR+3    //����Խ��
#define ERROR_REOPERATION		USER_ERROR+4    //�ظ�����
#define ERROR_WSASTARTUP		USER_ERROR+5    //WSAStartupִ��ʧ��
#define ERROR_CREATEMSG			USER_ERROR+6    //������Ϣѭ��ʧ��
#define ERROR_NOSUPPORTRECORD   USER_ERROR+7    //��֧��ǰ��¼��
#define ERROR_INITCHANNELNET    USER_ERROR+8    //ͨ�����紴��ʧ��
#define ERROR_CREATEDDRAW       USER_ERROR+9    //�޷����������DirectDraw
#define ERROR_NO_CHANNEL		USER_ERROR+10   //ͨ��û�д���
#define ERROR_NO_FUN            USER_ERROR+11   //�޴˹���
#define ERROR_PARAM_INVALID     USER_ERROR+12   //������Ч 
#define ERROR_DEV_FULL			USER_ERROR+13   //�豸�б�����
#define ERROR_LOGON				USER_ERROR+14   //�豸�Ѿ���¼�����ڵ�¼
#define ERROR_CREATECPUTHREAD   USER_ERROR+15   //����CPU����߳�ʧ��
#define ERROR_CREATEPLAYER      USER_ERROR+16   //����Playerʧ��
#define ERROR_NOAUTHORITY		USER_ERROR+17   //Ȩ�޲���
#define ERROR_NOTALK            USER_ERROR+18   //δ�Խ�
#define ERROR_NOCALLBACK		USER_ERROR+19   //û���豸�ص�����
#define ERROR_CREATEFILE        USER_ERROR+20   //�����ļ�ʧ��
#define ERROR_NORECORD			USER_ERROR+21   //���Ǵӵ�ǰPlayer�����¼��
#define ERROR_NOPLAYER			USER_ERROR+22   //û�ж�ӦPlayer
#define ERROR_INITCHANNEL       USER_ERROR+23   //ͨ��û�г�ʼ��
#define ERROR_NOPLAYING         USER_ERROR+24   //Playerû�в���
#define ERROR_PARAM_LONG		USER_ERROR+25   //�ַ����������ȹ���
#define ERROR_INVALID_FILE      USER_ERROR+26   //�ļ�������Ҫ��
#define ERROR_USER_FULL			USER_ERROR+27   //�û��б�����
#define ERROR_USER_DEL			USER_ERROR+28   //��ǰ�û��޷�ɾ��
#define ERROR_CARD_LOAD			USER_ERROR+29	//���ؿ�dllʧ��
#define ERROR_CARD_CORE			USER_ERROR+30	//���ؿ��ں�ʧ��
#define ERROR_CARD_COREFILE		USER_ERROR+31	//���ؿ��ں��ļ�ʧ��
#define ERROR_CARD_INIT			USER_ERROR+32	//����ʼ��ʧ��
#define ERROR_CARD_COREREAD		USER_ERROR+33	//��ȡ���ں��ļ�ʧ��
#define ERROR_CHARACTER_LOAD	USER_ERROR+34	//�����ֿ�ʧ��
#define ERROR_NOCARD			USER_ERROR+35   //��δ��ʼ��
#define ERROR_SHOW_MODE			USER_ERROR+36   //��ʾģʽδ����
#define ERROR_FUN_LOAD			USER_ERROR+37	//����δ����
#define ERROR_CREATE_DOWNLOAD	USER_ERROR+38	//û�и��������ͨ������
#define	ERROR_PROXY_DELACT		USER_ERROR+39   //ɾ����������ģʽ�ķ�����
#define ERROR_PROXY_HASCONNECT	USER_ERROR+40	//��������
#define ERROR_PROXY_NOPROXY		USER_ERROR+41   //����û������
#define ERROR_PROXY_IDENTITY	USER_ERROR+42	//���Ǵ�������
#define	ERROR_CONNECT_MAX		USER_ERROR+43	//�����Ѿ��������
#define	ERROR_NO_DISK			USER_ERROR+44	//û�йҽӴ洢�豸

#define ERROR_ALREADY_INTERTALK			(USER_ERROR+0x32)		//	���ڽ���˫��Խ�
#define ERROR_FUNCTION_NOT_SUPPORTED	(USER_ERROR+0x33)		//	���ܲ������豸��֧��
#define ERROR_DISPLAY_ON_OTHER_WND		(USER_ERROR+0x34)		//	����������������ʾ
#define ERROR_BUFFER_TOO_SMALL	(USER_ERROR+0x35)		//	������̫С
#define ERROR_NVR_NOT_SUPPORT	(USER_ERROR+0x36)		//	���豸��֧��NVR��ع���

#define	ERROR_EVENT_NOT_ENABLE	(USER_ERROR+0x38)		//	�������д��¼�û��ʹ��
#define ERROR_RULE_NOT_ENALE	(USER_ERROR+0x39)		//	�˹���û��ʹ��
#define ERROR_UNSUPPORT_STREAM	(USER_ERROR+0x40)		//	��֧����������

#endif
