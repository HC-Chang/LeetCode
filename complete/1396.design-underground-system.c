/*
 * @lc app=leetcode id=1396 lang=c
 *
 * [1396] Design Underground System
 */

// @lc code=start
#define MaxIndex 20001
#define maxLengStation 12
#define MaxHashID 1000001

typedef struct
{
    int passagerID[MaxIndex];
    int passagerNumber;
    int hashID[MaxHashID];
    char **startStation;
    int startTime[MaxIndex];
    char **endStation;
    int endTime[MaxIndex];
} UndergroundSystem;

int g_tackNumber;
double g_avergeTime[MaxIndex];
int g_trackTimes[MaxIndex];
char **g_travelTrack;

UndergroundSystem *undergroundSystemCreate()
{
    g_tackNumber = 0;
    memset(g_avergeTime, 0, sizeof(g_avergeTime));
    memset(g_trackTimes, 0, sizeof(g_trackTimes));
    g_travelTrack = (char **)malloc(sizeof(char *) * MaxIndex);

    UndergroundSystem *obj = (UndergroundSystem *)malloc(sizeof(UndergroundSystem));

    obj->startStation = (char **)malloc(sizeof(char *) * MaxIndex);
    obj->endStation = (char **)malloc(sizeof(char *) * MaxIndex);

    for (int i = 0; i < MaxIndex; i++)
    {
        obj->startStation[i] = (char *)malloc(sizeof(char) * maxLengStation);
        obj->endStation[i] = (char *)malloc(sizeof(char) * maxLengStation);
        g_travelTrack[i] = (char *)malloc(sizeof(char) * maxLengStation * 2);
    }

    obj->passagerNumber = 0;
    memset(obj->hashID, 0, sizeof(obj->hashID));
    return obj;
}
void undergroundSystemCheckIn(UndergroundSystem *obj, int id, char *stationName, int t)
{
    if (!obj)
        return;
    if (obj->hashID[id] != 0)
        return;
    obj->passagerID[obj->passagerNumber] = id;
    obj->startStation[obj->passagerNumber] = stationName;
    obj->startTime[obj->passagerNumber] = t;
    obj->hashID[id] = id;
    obj->passagerNumber++;
}
void undergroundSystemCheckOut(UndergroundSystem *obj, int id, char *stationName, int t)
{
    if (!obj)
        return;
    if (obj->hashID[id] == 0)
        return;

    for (int i = 0; i < obj->passagerNumber; i++)
    {
        if (obj->passagerID[i] == id)
        {
            obj->endTime[i] = t;
            char *tmpStation = (char *)malloc(sizeof(char) * maxLengStation * 2);
            strcpy(tmpStation, obj->startStation[i]);
            strcat(tmpStation, "-");
            tmpStation = strcat(tmpStation, stationName);
            for (int j = 0; j < g_tackNumber; j++)
            {
                if (!strcmp(tmpStation, g_travelTrack[j]))
                {
                    g_avergeTime[j] = g_avergeTime[j] + t - obj->startTime[i];
                    g_trackTimes[j]++;
                    break;
                }
            }
            g_avergeTime[g_tackNumber] = t - obj->startTime[i];
            g_trackTimes[g_tackNumber]++;
            g_travelTrack[g_tackNumber] = tmpStation;
            g_tackNumber++;
        }
    }

    for (int i = 0; i < obj->passagerNumber; i++)
    {
        if (obj->passagerID[i] == obj->hashID[id])
        {
            obj->passagerID[i] = 0;
            break;
        }
    }
    obj->hashID[id] = 0;
}
double undergroundSystemGetAverageTime(UndergroundSystem *obj, char *startStation, char *endStation)
{
    if (obj == NULL)
        return 0.0;
    char *tmpStation = (char *)malloc(sizeof(char) * maxLengStation * 2);
    strcpy(tmpStation, startStation);
    strcat(tmpStation, "-");
    tmpStation = strcat(tmpStation, endStation);
    for (int i = 0; i < g_tackNumber; i++)
    {
        if (!strcmp(tmpStation, g_travelTrack[i]))
            return (g_avergeTime[i] / g_trackTimes[i]);
    }
    return 0.0;
}
void undergroundSystemFree(UndergroundSystem *obj)
{
    free(obj);
}

/**
 * Your UndergroundSystem struct will be instantiated and called as such:
 * UndergroundSystem* obj = undergroundSystemCreate();
 * undergroundSystemCheckIn(obj, id, stationName, t);

 * undergroundSystemCheckOut(obj, id, stationName, t);

 * double param_3 = undergroundSystemGetAverageTime(obj, startStation, endStation);

 * undergroundSystemFree(obj);
*/
// @lc code=end
