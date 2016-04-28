#ifndef IVIDEOSERVER_H
#define IVIDEOSERVER_H
#include <Windows.h>
#include <windef.h>
#include <vector>
#include <map>
#include <string>
#include <mutex>


#if defined(VIDEOSERVER_LIBRARY)
#  define VIDEOSERVER_EXPORT __declspec(dllexport)
#else
#  define VIDEOSERVER_EXPORT __declspec(dllimport)
#endif

#define SHE_BEGING __try{ std::cout<<"she try beg"<<std::endl;

#define SHE_END  std::cout<<"she try end"<<std::endl;}__except(EXCEPTION_EXECUTE_HANDLER) \
{ \
    addLog("unkonw error!", __LINE__);\
}

#define SHE_END_RETURN(returnValue) }__except(EXCEPTION_EXECUTE_HANDLER) \
{ \
    addLog("unkonw error!", __LINE__);\
   return returnValue; \
}

#define SHE_END_RETURN_FALSE SHE_END_RETURN(false)


typedef long long  download_handle_t;
typedef long long  play_handle_t;

//����ID
enum DeviceFactory
{
    SISC_IPC_DH = 0,                                  // ��
    SISC_IPC_GZLL = 1,                                // ��������
	SISC_IPC_DIZHIPU = 2,							  // ������
	SISC_IPC_HAISHITAI = 3,							  // ����̩
	SISC_IPC_XINDAGONGCHUANG = 4,					  // �´ﹲ��
	SISC_IPC_XP = 5,								  // ��������
	SISC_IPC_BLUESKY = 6,							  // ��ɫ�Ǽ�
	SISC_IPC_DEJIALA = 7,							  // �¼���
	SISC_IPC_JUNMINGSHI = 8,                          // ������
	SISC_IPC_JIUAN = 9,							      // �Ű����
	SISC_IPC_LIANDA = 10,							  // ������
	SISC_IPC_SILANG = 11,							  // ����˼��
	SISC_IPC_JIRUI = 12,							  // ����
	SISC_IPC_TAIKANGWEIYE = 13,					      // ̩��ΰҵ
	SISC_IPC_XINWANGRUIJIE = 14,				      // �������
	SISC_IPC_ZHONGTIANANBAO = 15,				      // ���ﰲ��
	SISC_IPC_TIANSHIDA = 16,			    	      // ���Ӵ�
	SISC_IPC_DOANGYANG = 17,			    	      // ��������
	SISC_IPC_YUNDIANSHI = 18,			    	      // �Ƶ���
	SISC_IPC_KUANGSHIAN = 19,			    	      // ���Ӱ�
	SISC_IPC_HONGKANGWEISHI = 20,			    	  // �꿵����
	SISC_IPC_SHENZHENTONGWEI = 21,			    	  // ����ͬΪ
	SISC_IPC_DALIKEJI = 22,			    	          // �����Ƽ�
	SISC_IPC_SHIXINGANFANG = 23,			    	  // ���ǰ���
	SISC_IPC_SHOUWEIZHE = 24,			         	  // ������
	SISC_IPC_HUONIWEIER = 25,			         	  // ����Τ��
	SISC_IPC_NANNINGGUANGTAI = 26,			          // ������̩
	SISC_IPC_GUANGDONGLINYU = 27,			          // �㶫����
	SISC_IPC_HANGJINGKEJI = 28,		     	          // �����Ƽ�

	SISC_IPC_BAOXINGSHENG = 29,		     	          // ����ʢ
	SISC_IPC_LANDAOEMHK = 30,		     	          // ������OEM����
	SISC_IPC_XIANHAIFANG = 31,		     	          // ��������OEM����
	SISC_IPC_BEIJINGZHENGFANG = 32,		     	      // ��������ʱ��OEM����
	SISC_IPC_TAIKANGWEIYEOEMHK = 33,		     	  // ̩��ΰҵOEM����
	SISC_IPC_TIANMIN = 34,		     	              // ����
	SISC_IPC_KEEN = 35,		     	                  // �ƶ�
	SISC_IPC_MEIFANGWEIYE = 36,		     	          // ����ΰҵ
	SISC_IPC_GUANGZHOUBANGSHI = 37,		     	      // ���ݰ�������
	SISC_IPC_GUANGZHOUSHIAN = 38,		     	      // �����Ӱ�����
	SISC_IPC_QIAOAN = 39,		     	              // �ǰ�
	SISC_IPC_LANGSHIXIN = 40,		     	          // ������
	SISC_IPC_YAAN = 41,		     	                  // �ǰ�
	SISC_IPC_TAIWEIGAOKE = 42,		     	          // ̩���߿�
	SISC_IPC_HUABANGHAISHI = 43,		     	      // �����
	SISC_IPC_GUANGZHOUYISHI = 44,		     	      // ��������
	SISC_IPC_HONGKANGWEISHIOEMXM = 45,		     	  // ���ں꿵����OEM����
	SISC_IPC_ANJULIAO = 46,		     	              // ������
	SISC_IPC_YIRONGGUANSHI = 47,		     	      // �������ڹ���
	SISC_IPC_DONGDAJIZHI = 48,		     	          // �������ƽ̨
	SISC_IPC_GERECORDER = 49,		     	          // GEӲ��¼���

	SISC_IPC_MIKA61 = 50,		     	              // �����׿�61ϵ��
	SISC_IPC_MIKA8081 = 51,		     	              // �����׿�8081ϵ��NVR
	SISC_IPC_HENGYI = 52,		     	              // ����
	SISC_IPC_BAAN = 53,		         	              // ���ڰ˰�
	SISC_IPC_BAIHUI = 54,		         	          // ���ڰٻ�
	SISC_IPC_HAISHIAN = 55,		         	          // ���ں��Ӱ�
	SISC_IPC_JUFU = 56,		            	          // ���ھ��J
	SISC_IPC_SAIQING = 57,		         	          // ��������
	SISC_IPC_XINGKEAN = 58,		         	          // �����˿ư�
	SISC_IPC_TIANTIANYOU = 59,		         	      // ������

    SISC_IPC_HB = 60,                                 // ����
    SISC_IPC_TDWY = 61,                               // ���ΰҵ
	SISC_IPC_XM = 62,                                 // ����
	SISC_IPC_GZHX = 63,   						      // ���ݺ���
	SISC_IPC_SNA = 64,   						      // ʩ�Ͱ�
	SISC_IPC_JF = 65,   						      // �޷�
	SISC_IPC_SALX = 66,   						      // ʨ����Ѷ
	SISC_IPC_WSD = 67,   						      // ���˴�
	SISC_IPC_HIKVISION = 100,                         // ����
	SISC_IPC_ZHONGWEI = 101,                          // ��ά

    SISC_IPC_ZHENSHISHUN = 1001,                      // ����˳
    SISC_IPC_JINSHANPINKE,                            // ��ɽƷ��
    SISC_IPC_XUFENGWS,                                // �������
    SISC_IPC_XINGSHIBAO,                              // ���ӱ�

    SISC_IPC_ZSB,                                  // ���Ӱ�
    SISC_IPC_KER,                            // ������
    SISC_IPC_AN,                                // ����
    SISC_IPC_AWT,                              // ������

    SISC_IPC_JAA,                      // ������
    SISC_IPC_XJX,                            // �ν�Ѷ
    SISC_IPC_HY,                                // ����
    SISC_IPC_QX,                              // ��о

    SISC_IPC_YK,                      // �ʿ�
    SISC_IPC_JAB,                            // �Ӱ���
    SISC_IPC_NZ,                                // ����
    SISC_IPC_LZJ,                              // ��֮��

    SISC_IPC_SX,                      // ����
    SISC_IPC_WTS,                            // ������
    SISC_IPC_AZX,                                // ��֮Ѷ
    SISC_IPC_BKB,                              // �ٿƲ�

    SISC_IPC_DTHQ,                      // ���ƻ�ǿ
    SISC_IPC_HAIY,                            // ����
    SISC_IPC_ALKJ,                                // ��������
    SISC_IPC_XTKJ,                              // �����Ƽ�

    SISC_IPC_HXGJ,                      // �������
    SISC_IPC_ERJIA,                            // ����
    SISC_IPC_HWSX,                                // ��Ϊ��Ѷ
    SISC_IPC_XINGRQ,                              // ����Ȫ

    SISC_IPC_XMDZ,                      // г������
    SISC_IPC_AOKS,                            // �Ŀ�ɭ
    SISC_IPC_HRRS,                                // �������
    SISC_IPC_AJKJ,                              // ���οƼ�

    SISC_IPC_NAKJ,                      // �ᰲ�Ƽ�
    SISC_IPC_LTSX,                            // ��ͼ��Ѷ
    SISC_IPC_WEIDS,                                // ����˹
    SISC_IPC_SZSBD,                              // �����б���

    SISC_IPC_YMKJ,                      // ӡ�οƼ�
    SISC_IPC_RUILT,                            // ������
    SISC_IPC_YINGFT,                                // Ӣ����
    SISC_IPC_LATX,                              // ��������

    SISC_IPC_WBDZ,                      // ά�����
    SISC_IPC_XRHK,                            // ���񻪿�
    SISC_IPC_DBDZ,                                // �㲩����
    SISC_IPC_FEIHX,                              // �ɺ���

    SISC_IPC_CHAOBL,                      // ������
    SISC_IPC_YSSM,                            // ��˸��ó
    SISC_IPC_PANK,                                // �����
    SISC_IPC_BAOJS,                              // ���Ӽ�

    SISC_IPC_KELAN,                      // ����
    SISC_IPC_BEIST,                            // ����ͨ
    SISC_IPC_KDKJ,                                // �ƴ�Ƽ�
    SISC_IPC_SBZN,                              // ɽ������

    SISC_IPC_JINGDR,                      // ������
    SISC_IPC_HZSS,                            // ����ʥ��
    SISC_IPC_HTDF,                                // ���Ͷ���
    SISC_IPC_XBWS,                              // �Ǳ�����

    SISC_IPC_BJYKJY,                      // ����Ӣ����ҵ
    SISC_IPC_GZSTH,                            // ������̩��
    SISC_IPC_SZSAY,                                // �����а�ԣ
    SISC_IPC_GZZT,                              // ��������



    SISC_IPC_UNDEFINE = 9999,                         // δ����
};

// �豸��Ϣ
struct DeviceInfo
{
    DeviceInfo()
    {
        Factory = SISC_IPC_UNDEFINE;
		szIP = "";
        nPort = 0;
    }

    DeviceInfo(const DeviceInfo &other)
    {
        Factory = other.Factory;
        szIP = other.szIP;
        nPort = other.nPort;
    }
    DeviceInfo& operator = (const DeviceInfo &other)
    {
        if (this != &other)
        {
            Factory = other.Factory;
            szIP = other.szIP;
            nPort = other.nPort;
         }

        return *this;
    }

    DeviceFactory Factory;
    std::string szIP;
    __int32 nPort;
};

struct IVideoServer;
struct IVideoServerFactory
{
	IVideoServerFactory() : m_init(false)
    {
		m_OemFlag = false;
    }
    virtual ~IVideoServerFactory()
    {
    }
    virtual void destroy()
    {
        delete this;
    }

    //��ʼ��SDK
    virtual bool init() = 0;
    /*
     * �ͷ�SDK
     */
    virtual void clean() = 0;
    //������Ƶ������
    virtual IVideoServer* create() = 0;
    //��������
    virtual const char* name() = 0;
    //����ID
    virtual DeviceFactory factory() = 0;
    //��Ƶ��׺
    virtual void videoFileExterns(std::vector<std::string>& externs) = 0;
    virtual const char* getLastError()
    {
        return m_sLastError.c_str();
    }
    //Ĭ�϶˿�
    virtual int defaultPort() = 0;
    //Ĭ���û�
    virtual const char* defaultUser() = 0;
    //Ĭ������
    virtual const char* defaultPasswords() = 0;
	
	virtual bool IsOEMFac()
	{
		return m_OemFlag;
	}
protected:
    bool m_init;
    std::string  m_sLastError;

protected:
	bool m_OemFlag;
};
//������Ƶ�ļ���Ϣ
struct RecordFile
{
    RecordFile()
    {
        channel = 0;
        size = 0;
        pPrivateData = nullptr;
        PrivateDataDataSize = 0;
    }

    ~RecordFile()
    {
        if (nullptr != pPrivateData)
        {
            delete pPrivateData;
            pPrivateData = nullptr;
            PrivateDataDataSize = 0;
        }
    }

    RecordFile(const RecordFile& other)
    {
        channel = other.channel;
        size = other.size;
        name = other.name;
        beginTime = other.beginTime;
        endTime = other.endTime;
        pPrivateData = nullptr;
        PrivateDataDataSize = 0;
        setPrivateData(other.pPrivateData, other.PrivateDataDataSize);
    }

    RecordFile& operator= (const RecordFile& other)
    {
        if (&other == this)
        {
            return *this;
        }
        channel = other.channel;
        size = other.size;
        name = other.name;
        beginTime = other.beginTime;
        endTime = other.endTime;
        setPrivateData(other.pPrivateData, other.PrivateDataDataSize);
        return *this;
    }

    void setPrivateData(void* pData, int size)
    {
        if (nullptr != pPrivateData)
        {
            delete pPrivateData;
            pPrivateData = nullptr;
            PrivateDataDataSize = 0;
        }


        if (size > 0)
        {
            pPrivateData = new char[size];
            PrivateDataDataSize = size;
            memcpy(pPrivateData, pData, size);
        }
    }
    //ȡ��˽������
    void* getPrivateData() const
    {
        return pPrivateData;
    }
    __int32 getPrivateDataSize() const
    {
        return PrivateDataDataSize;
    }

    __int32 channel;      //ͨ��
    __int64 size;         //�ļ���С(byte)
    std::string  name;    //�ļ�����
    __time64_t beginTime; //����ʱ��
    __time64_t endTime;   //����ʱ��
    char* pPrivateData;   //˽������
    __int32 PrivateDataDataSize;//˽�����ݴ�С
};

struct IVideoServer
{

    IVideoServer() : m_lLoginHandle(0)
    {

    }

    virtual void destroy()
    {
        delete this;
    }

    virtual ~IVideoServer()
    {
    }

    virtual const char* getLastError()
    {
        return m_sLastError.c_str();
    }
    //��ȿ�¡һ��������
    virtual IVideoServer* clone() = 0;
    /*
     *  ��¼����
     *  @param [in] IP ��¼��IP
     *  @param [in] port �˿ں�
     *  @param [in] user �û���
     *  @param [in] password ����
     *  @param [out] channels ͨ����
     *  @return �Ƿ�ɹ�
     */
    virtual bool login(const char* IP, __int32 port, const char* user,
        const char* password, std::map<__int32, std::string>& channels) = 0;
    //�˳�
    virtual bool logout() = 0;
    /*
     * ��ȡ�ļ��б�
     *  @param [out] files �ļ��б�
     *  @param [in] nChannelId ͨ����
     *  @param [in] timeStart ��ʼʱ��
     *  @param [in] timeEnd ����ʱ��
     *  @return �Ƿ�ɹ�
     */
    virtual bool GetRecordFileList(std::vector<RecordFile>& files, const std::vector<int > &channelVec, __time64_t timeStart,
                                    __time64_t timeEnd) = 0;
    /*
     * �ļ�����
     *  @param [in] saveFileName �����ļ�����ȫ·����
     *  @param [in] file ��Ƶ�ļ���Ϣ
     *  @param [out] hdl ��������ID
     *  @return �ɹ����
     */
    virtual bool downLoadByRecordFile(const char* saveFileName, const RecordFile& file, download_handle_t& hdl) = 0;
    /*
     *  ֹͣ����
     *  @param [in] h downLoadByRecordFile���ص�����ID
     *  @return ����true/false
     */
    virtual bool stopDownload(download_handle_t h) = 0;
    /*
     *  ��ƵԤ��
     *  @param [in] file ��Ƶ�ļ���Ϣ
     *  @param [in] hwnd ���Ŵ��ھ��
     *  @param [out] playbackHandle ���ز���ID
     *  @return ����true/false
     */
    virtual bool  PlayBackByRecordFile(const RecordFile& file, HWND hwnd, play_handle_t& playbackHandle) = 0;

    /*
     *  ���ò���λ��
     *  @param [in] playbackHandle PlayBackByRecordFile���صĲ���ID
     *  @param [in] pos ��0 - 100��
     *  @return ����true/false
     */
    virtual bool SetPlayBack(__int64 playbackHandle, __int32 pos) = 0;
    /*
     *  ֹͣ��ƵԤ��
     *  @param [in] playbackHandle PlayBackByRecordFile���صĲ���ID
     *  @param [in] mPause �Ƿ�����ͣ 1����ͣ 0����
     *  @return ����true/false
     */
    virtual bool StopPlayBack(__int64 playbackHandle, __int32 mPause) = 0;
    virtual bool getPlayBackPos(__int64 playbackHandle, __int32* pos)
    {
        return false;
    }

    virtual bool getDownloadPos(download_handle_t h, __int64* totalSize, __int64* currentSize, bool* failed)
    {
        return false;
    }

protected:
    std::string m_sLastError;
    long m_lLoginHandle;
    std::recursive_mutex m_mutexDownload;
};

#if defined(VIDEOSERVER_LIBRARY)
extern "C" VIDEOSERVER_EXPORT IVideoServerFactory* VideoServerFactory();
#else

typedef void* (*pfExternFun)(IVideoServer* server, void* externParams);

//�Ƿ���Ԥ����Ƶ
//externParams ���� ����
//����ֵ���� bool (Ĭ��true)
#define EXTERN_FUN_CAN_PLAY_BACK "canPlayBack"


typedef IVideoServerFactory* (*pfGetVideoServerFactory)();
#endif


#endif // IVIDEOSERVER_H