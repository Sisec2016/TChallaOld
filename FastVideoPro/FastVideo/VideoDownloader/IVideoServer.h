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
    ETIM_IPC_DH = 0,                                  // ��
    ETIM_IPC_GZLL = 1,                                // ��������
	ETIM_IPC_DIZHIPU = 2,							  // ������
	ETIM_IPC_HAISHITAI = 3,							  // ����̩
	ETIM_IPC_XINDAGONGCHUANG = 4,					  // �´ﹲ��
	ETIM_IPC_XP = 5,								  // ��������
	ETIM_IPC_BLUESKY = 6,							  // ��ɫ�Ǽ�
	ETIM_IPC_DEJIALA = 7,							  // �¼���
	ETIM_IPC_JUNMINGSHI = 8,                          // ������
	ETIM_IPC_JIUAN = 9,							      // �Ű����
	ETIM_IPC_LIANDA = 10,							  // ������
	ETIM_IPC_SILANG = 11,							  // ����˼��
	ETIM_IPC_JIRUI = 12,							  // ����
	ETIM_IPC_TAIKANGWEIYE = 13,					      // ̩��ΰҵ
	ETIM_IPC_XINWANGRUIJIE = 14,				      // �������
	ETIM_IPC_ZHONGTIANANBAO = 15,				      // ���ﰲ��
	ETIM_IPC_TIANSHIDA = 16,			    	      // ���Ӵ�
	ETIM_IPC_DOANGYANG = 17,			    	      // ��������
	ETIM_IPC_YUNDIANSHI = 18,			    	      // �Ƶ���
	ETIM_IPC_KUANGSHIAN = 19,			    	      // ���Ӱ�
	ETIM_IPC_HONGKANGWEISHI = 20,			    	  // �꿵����
	ETIM_IPC_SHENZHENTONGWEI = 21,			    	  // ����ͬΪ
	ETIM_IPC_DALIKEJI = 22,			    	          // �����Ƽ�
	ETIM_IPC_SHIXINGANFANG = 23,			    	  // ���ǰ���
	ETIM_IPC_SHOUWEIZHE = 24,			         	  // ������
	ETIM_IPC_HUONIWEIER = 25,			         	  // ����Τ��
	ETIM_IPC_NANNINGGUANGTAI = 26,			          // ������̩
	ETIM_IPC_GUANGDONGLINYU = 27,			          // �㶫����
	ETIM_IPC_HANGJINGKEJI = 28,		     	          // �����Ƽ�

	ETIM_IPC_BAOXINGSHENG = 29,		     	          // ����ʢ
	ETIM_IPC_LANDAOEMHK = 30,		     	          // ������OEM����
	ETIM_IPC_XIANHAIFANG = 31,		     	          // ��������OEM����
	ETIM_IPC_BEIJINGZHENGFANG = 32,		     	      // ��������ʱ��OEM����
	ETIM_IPC_TAIKANGWEIYEOEMHK = 33,		     	  // ̩��ΰҵOEM����
	ETIM_IPC_TIANMIN = 34,		     	              // ����
	ETIM_IPC_KEEN = 35,		     	                  // �ƶ�
	ETIM_IPC_MEIFANGWEIYE = 36,		     	          // ����ΰҵ
	ETIM_IPC_GUANGZHOUBANGSHI = 37,		     	      // ���ݰ�������
	ETIM_IPC_GUANGZHOUSHIAN = 38,		     	      // �����Ӱ�����
	ETIM_IPC_QIAOAN = 39,		     	              // �ǰ�
	ETIM_IPC_LANGSHIXIN = 40,		     	          // ������
	ETIM_IPC_YAAN = 41,		     	                  // �ǰ�
	ETIM_IPC_TAIWEIGAOKE = 42,		     	          // ̩���߿�
	ETIM_IPC_HUABANGHAISHI = 43,		     	      // �����
	ETIM_IPC_GUANGZHOUYISHI = 44,		     	      // ��������
	ETIM_IPC_HONGKANGWEISHIOEMXM = 45,		     	  // ���ں꿵����OEM����
	ETIM_IPC_ANJULIAO = 46,		     	              // ������
	ETIM_IPC_YIRONGGUANSHI = 47,		     	      // �������ڹ���
	ETIM_IPC_DONGDAJIZHI = 48,		     	          // �������ƽ̨
	ETIM_IPC_GERECORDER = 49,		     	          // GEӲ��¼���

	ETIM_IPC_MIKA61 = 50,		     	              // �����׿�61ϵ��
	ETIM_IPC_MIKA8081 = 51,		     	              // �����׿�8081ϵ��NVR
	ETIM_IPC_HENGYI = 52,		     	              // ����
	ETIM_IPC_BAAN = 53,		         	              // ���ڰ˰�
	ETIM_IPC_BAIHUI = 54,		         	          // ���ڰٻ�
	ETIM_IPC_HAISHIAN = 55,		         	          // ���ں��Ӱ�
	ETIM_IPC_JUFU = 56,		            	          // ���ھ��J
	ETIM_IPC_SAIQING = 57,		         	          // ��������
	ETIM_IPC_XINGKEAN = 58,		         	          // �����˿ư�
	ETIM_IPC_TIANTIANYOU = 59,		         	      // ������

    ETIM_IPC_HB = 60,                                 // ����
    ETIM_IPC_TDWY = 61,                               // ���ΰҵ
	ETIM_IPC_XM = 62,                                 // ����
	ETIM_IPC_GZHX = 63,   						      // ���ݺ���
	ETIM_IPC_SNA = 64,   						      // ʩ�Ͱ�
	ETIM_IPC_JF = 65,   						      // �޷�
	ETIM_IPC_SALX = 66,   						      // ʨ����Ѷ
	ETIM_IPC_WSD = 67,   						      // ���˴�
	ETIM_IPC_HIKVISION = 100,                         // ����
	ETIM_IPC_ZHONGWEI = 101,                          // ��ά

    ETIM_IPC_ZHENSHISHUN = 1001,                      // ����˳
    ETIM_IPC_JINSHANPINKE,                            // ��ɽƷ��
    ETIM_IPC_XUFENGWS,                                // �������
    ETIM_IPC_XINGSHIBAO,                              // ���ӱ�

    ETIM_IPC_ZSB,                                  // ���Ӱ�
    ETIM_IPC_KER,                            // ������
    ETIM_IPC_AN,                                // ����
    ETIM_IPC_AWT,                              // ������

    ETIM_IPC_JAA,                      // ������
    ETIM_IPC_XJX,                            // �ν�Ѷ
    ETIM_IPC_HY,                                // ����
    ETIM_IPC_QX,                              // ��о

    ETIM_IPC_YK,                      // �ʿ�
    ETIM_IPC_JAB,                            // �Ӱ���
    ETIM_IPC_NZ,                                // ����
    ETIM_IPC_LZJ,                              // ��֮��

    ETIM_IPC_SX,                      // ����
    ETIM_IPC_WTS,                            // ������
    ETIM_IPC_AZX,                                // ��֮Ѷ
    ETIM_IPC_BKB,                              // �ٿƲ�

    ETIM_IPC_DTHQ,                      // ���ƻ�ǿ
    ETIM_IPC_HAIY,                            // ����
    ETIM_IPC_ALKJ,                                // ��������
    ETIM_IPC_XTKJ,                              // �����Ƽ�

    ETIM_IPC_HXGJ,                      // �������
    ETIM_IPC_ERJIA,                            // ����
    ETIM_IPC_HWSX,                                // ��Ϊ��Ѷ
    ETIM_IPC_XINGRQ,                              // ����Ȫ

    ETIM_IPC_XMDZ,                      // г������
    ETIM_IPC_AOKS,                            // �Ŀ�ɭ
    ETIM_IPC_HRRS,                                // �������
    ETIM_IPC_AJKJ,                              // ���οƼ�

    ETIM_IPC_NAKJ,                      // �ᰲ�Ƽ�
    ETIM_IPC_LTSX,                            // ��ͼ��Ѷ
    ETIM_IPC_WEIDS,                                // ����˹
    ETIM_IPC_SZSBD,                              // �����б���

    ETIM_IPC_YMKJ,                      // ӡ�οƼ�
    ETIM_IPC_RUILT,                            // ������
    ETIM_IPC_YINGFT,                                // Ӣ����
    ETIM_IPC_LATX,                              // ��������

    ETIM_IPC_WBDZ,                      // ά�����
    ETIM_IPC_XRHK,                            // ���񻪿�
    ETIM_IPC_DBDZ,                                // �㲩����
    ETIM_IPC_FEIHX,                              // �ɺ���

    ETIM_IPC_CHAOBL,                      // ������
    ETIM_IPC_YSSM,                            // ��˸��ó
    ETIM_IPC_PANK,                                // �����
    ETIM_IPC_BAOJS,                              // ���Ӽ�

    ETIM_IPC_KELAN,                      // ����
    ETIM_IPC_BEIST,                            // ����ͨ
    ETIM_IPC_KDKJ,                                // �ƴ�Ƽ�
    ETIM_IPC_SBZN,                              // ɽ������

    ETIM_IPC_JINGDR,                      // ������
    ETIM_IPC_HZSS,                            // ����ʥ��
    ETIM_IPC_HTDF,                                // ���Ͷ���
    ETIM_IPC_XBWS,                              // �Ǳ�����

    ETIM_IPC_BJYKJY,                      // ����Ӣ����ҵ
    ETIM_IPC_GZSTH,                            // ������̩��
    ETIM_IPC_SZSAY,                                // �����а�ԣ
    ETIM_IPC_GZZT,                              // ��������



    ETIM_IPC_UNDEFINE = 9999,                         // δ����
};

// �豸��Ϣ
struct DeviceInfo
{
    DeviceInfo()
    {
        Factory = ETIM_IPC_UNDEFINE;
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