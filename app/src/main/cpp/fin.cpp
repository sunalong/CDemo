//
// Created by sunalong on 16/12/28 14:14.
// Email:466210864@qq.com
//

#define    MODE_NONE                    -1
#define    MODE_IN_CALL                2
#define    MODE_IN_COMMUNICATION        3
#define    MODE_NORMAL                    0

#define    STREAM_MUSIC                3
#define    STREAM_VOICE_CALL            0
#define    STREAM_SYSTEM                1

#define    DEFAULT                        0
#define    MIC                            1
#define    VOICE_CALL                    4
#define    VOICE_RECOGNITION            6
#define    VOICE_COMMUNICATION            7

#define MODEL_NUM                    4


#define AUDIO_SETTING_NUMBER    4

#define AUDIO_TYPE_INDEX    0
#define STREAM_TYPE_INDEX    1
#define MIC_TYPE_INDEX        2
#define USE_BUILDIN_AEC        3

#include <iostream>

using namespace std;

typedef struct {
    char const *modelType;
    int modelTypeLength;
    //in byte
    int audioType;
    int streamType;
    int micType;
    bool useBuildInAec;
} audio_setting;

static audio_setting settings[MODEL_NUM] = {
//        {"GT-I9000",        8,          MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, DEFAULT,             true},
//        {"GT-N7100",        8,          MODE_IN_COMMUNICATION, STREAM_MUSIC,      VOICE_COMMUNICATION, true},
//        {"HUAWEI NXT-AL10", 15,         MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, VOICE_COMMUNICATION, true},
//        {"m1 metal",        8,          MODE_IN_CALL,          STREAM_VOICE_CALL, DEFAULT,             true},
//        {"SM-G9350",        8,          MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, VOICE_RECOGNITION,   true},
//        {"M681C",           5,          MODE_IN_CALL,          STREAM_VOICE_CALL, DEFAULT,             true},
//        {"OPPO R7",         7,          MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, DEFAULT,             true},
//        {"OPPO R9tm",       9,          MODE_IN_COMMUNICATION, STREAM_MUSIC,      VOICE_COMMUNICATION, true},
//        {"MX5",             3,          MODE_IN_COMMUNICATION, STREAM_MUSIC,      VOICE_COMMUNICATION, true},
//        {"Le X620",         7,          MODE_IN_COMMUNICATION, STREAM_MUSIC,      VOICE_COMMUNICATION, true},
//        {"m2 note",         7,          MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, DEFAULT,             true},
//        {"Redmi Note 3",    12,         MODE_IN_COMMUNICATION, STREAM_MUSIC,      VOICE_COMMUNICATION, true},
//        {"MI NOTE LTE",     11,         MODE_IN_COMMUNICATION, STREAM_MUSIC,      VOICE_COMMUNICATION, true},
//        {"MI 5", MODE_IN_COMMUNICATION, STREAM_MUSIC,          VOICE_COMMUNICATION, true},
//        {"Redmi Note 2",    12,         MODE_IN_COMMUNICATION, STREAM_MUSIC,      VOICE_COMMUNICATION, true},
//        {"OPPO A33m",       9,          MODE_IN_CALL,          STREAM_MUSIC,      VOICE_COMMUNICATION, true},
        {"OPPO R7s",  8, MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, VOICE_COMMUNICATION, true},
        {"SM-G9008W", 9, MODE_IN_CALL,          STREAM_VOICE_CALL, VOICE_COMMUNICATION, true},
        {"SM-G900**", 9, MODE_IN_CALL,          STREAM_VOICE_CALL, VOICE_COMMUNICATION, true},
        {"MI 4LTE",   7, MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, VOICE_COMMUNICATION, true},
//        {"A31",             3,          MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, VOICE_COMMUNICATION, true},
//        {"m1 note",         7,          MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, VOICE_RECOGNITION,   true},
//        {"GT-I9308",        8,          MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, VOICE_RECOGNITION,   true},
//        {"vivo X7Plus",     11,         MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, VOICE_RECOGNITION,   false},
//        {"OPPO R9s",        8,          MODE_IN_COMMUNICATION, STREAM_VOICE_CALL, VOICE_RECOGNITION,   false},
};

int mystrcmp(const char *str1, int length1, const char *str2, int length2) {
    if (length1 != length2) {
        return -1;
    }
    int res = 0;
    for (int i = 0; i < length1; i++) {
        char c1 = *(str1 + i);
        char c2 = *(str2 + i);
        if (c1 != c2) {
            res = -1;
            break;
        }
    }
    return res;
}

/**
 * 通配符
 */
int mystrcmpRegular(const char *str1, int length1, const char *str2, int length2) {
    if (length1 != length2) {
        return -1;
    }
    int res = -1;
    for (int i = 0; i < length1; i++) {
        char c1 = *(str1 + i);
        char c2 = *(str2 + i);
        if (i < 3) {//第四个字符才有可能是通配符，前面三个字符必须匹配，否则无法决断是哪类机型
            if (c1 != c2) {
                res = -1;
                break;
            }
        } else {
            //todo:如果一直匹配,就不用匹配符
            if (c1 == c2) {
                if (i == (length1 - 1)) {
                    return 0;
                }
            } else if (*(str2 + length2 - 1) == '*') {//从第四个字符就开始不匹配，走通配符
                if (c2 == '*') {
                    cout << str2 <<": 字符"<<c2<<"是通配符，i=" << i << endl;
                    return 0;
                }
            } else {//SM-G9009W str2:SM-G9008W 倒数第二位比较，不相同，还没找到通配符，即暂时没匹配
                return -1;
            }
        }
    }
    return res;
}

void audio_settings(const char *phoneModel, int *outSettings) {
    int phoneModelLength = strlen(phoneModel);
    for (int i = 0; i < MODEL_NUM; i++) {
        if (0 == mystrcmpRegular(phoneModel, phoneModelLength, settings[i].modelType, settings[i].modelTypeLength)) {
            cout << "main 匹配对： " << phoneModel << "<---->" << settings[i].modelType << endl;
            outSettings[AUDIO_TYPE_INDEX] = settings[i].audioType;
            outSettings[STREAM_TYPE_INDEX] = settings[i].streamType;
            outSettings[MIC_TYPE_INDEX] = settings[i].micType;
            outSettings[USE_BUILDIN_AEC] = settings[i].useBuildInAec;
            return;
        }
    }
    cout << "main 暂时无匹配： " << phoneModel << endl;
    outSettings[AUDIO_TYPE_INDEX] = MODE_IN_COMMUNICATION;
    outSettings[STREAM_TYPE_INDEX] = STREAM_MUSIC;
    outSettings[MIC_TYPE_INDEX] = VOICE_COMMUNICATION;
    outSettings[USE_BUILDIN_AEC] = true;
}

int main() {
    char *phoneModel = "SM-G900**";
    char *phoneModel2 = "SM-G9008W";
    char *phoneModel21 = "SM-G9008w";
    char *phoneModel3 = "SM-G9009W";
    char *phoneModel4 = "SM-G9009D";
    char *phoneModel5 = "MI 4LTE";
    char *phoneModel6 = "SMFf9008W";
    //set the audio settings
    int outSettings[AUDIO_SETTING_NUMBER];
    audio_settings(phoneModel, outSettings);
    cout << "-main--1--phoneModel:" << phoneModel << "  audio_type:" << outSettings[AUDIO_TYPE_INDEX] << " stream type:" <<
    outSettings[STREAM_TYPE_INDEX] << " "
            "mic_type:" << outSettings[MIC_TYPE_INDEX] << " use_aec:" << outSettings[USE_BUILDIN_AEC] << endl << endl;

    audio_settings(phoneModel2, outSettings);
    cout << "-main--2--phoneModel2:" << phoneModel2 << "  audio_type:" << outSettings[AUDIO_TYPE_INDEX] << " stream type:" <<
    outSettings[STREAM_TYPE_INDEX] << " "
            "mic_type:" << outSettings[MIC_TYPE_INDEX] << " use_aec:" << outSettings[USE_BUILDIN_AEC] << endl << endl;

    audio_settings(phoneModel21, outSettings);
    cout << "-main--21--phoneModel21:" << phoneModel21 << "  audio_type:" << outSettings[AUDIO_TYPE_INDEX] << " stream type:" <<
    outSettings[STREAM_TYPE_INDEX] << " "
            "mic_type:" << outSettings[MIC_TYPE_INDEX] << " use_aec:" << outSettings[USE_BUILDIN_AEC] << endl << endl;


    audio_settings(phoneModel3, outSettings);
    cout << "-main--3--phoneModel3:" << phoneModel3 << "  audio_type:" << outSettings[AUDIO_TYPE_INDEX] << " stream type:" <<
    outSettings[STREAM_TYPE_INDEX] << " "
            "mic_type:" << outSettings[MIC_TYPE_INDEX] << " use_aec:" << outSettings[USE_BUILDIN_AEC] << endl << endl;

    audio_settings(phoneModel4, outSettings);
    cout << "-main--4--phoneModel4:" << phoneModel4 << "  audio_type:" << outSettings[AUDIO_TYPE_INDEX] << " stream type:" <<
    outSettings[STREAM_TYPE_INDEX] << "  "
            "mic_type:" << outSettings[MIC_TYPE_INDEX] << " use_aec:" << outSettings[USE_BUILDIN_AEC] << endl << endl;


    audio_settings(phoneModel5, outSettings);
    cout << "-main--5--phoneModel5:" << phoneModel5 << "  audio_type:" << outSettings[AUDIO_TYPE_INDEX] << " stream type:" <<
    outSettings[STREAM_TYPE_INDEX] << "  "
            "mic_type:" << outSettings[MIC_TYPE_INDEX] << " use_aec:" << outSettings[USE_BUILDIN_AEC] << endl << endl;

    audio_settings(phoneModel6, outSettings);
    cout << "-main--6--phoneModel6:" << phoneModel6 << "  audio_type:" << outSettings[AUDIO_TYPE_INDEX] << " stream type:" <<
    outSettings[STREAM_TYPE_INDEX] << "  "
            "mic_type:" << outSettings[MIC_TYPE_INDEX] << " use_aec:" << outSettings[USE_BUILDIN_AEC] << endl << endl;

}

















