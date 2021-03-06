#ifndef INSCOREOBJECT_H
#define INSCOREOBJECT_H
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

/* **********************************************
 * Class describe an INScore object, with all
 * informations needed to create it.
 * **********************************************/

class INScoreObject
{
public:
    INScoreObject();
    INScoreObject(string _name, string _scene);

    ~INScoreObject();

    /* ************************************************
     * get and set methods
     * ************************************************/
    string getName() const;
    void setName(const string &value);

    string getScene() const;
    void setScene(const string &value);

    string getPath() const;
    void setPath(const string &value);

    string getType() const;
    string getType(int _i);
    void setType(const int value);
    void setType(const string value);

    string getCreationValue() const;
    void setCreationValue(const string &value);

    bool isParameterChecked(int _i);
    bool isParameterChecked(string _name);
    void setParameter(string _name, bool _value);

    string getParameterName(int i);

    bool getToCreate() const;
    void setToCreate(bool value);

    float getInitValue(const string valueName);
    void setInitValue(const string name, const float value);

    int nbTypes();
    int nbParameters();

    string getInitCommand();

    map<string, float> getInitValues() const;
    void setInitValues(const map<string, float> init);


    /* ************************************************
     * get and set for signal vector
     * ************************************************/
    string getSignal(int _i);
    int getSignalSize();

    string getBufferSize(int _i);
    string getSignalValue(int _i);


private:
    string name;
    string scene;
    string path;  // form : /ITL/sceneName/objectName
    string type;
    string creationValue;

    /* default initials values : modified by the "advanced options" */
    map<string, float> initValues {{"red", 0.0}, {"green", 0.0}, {"blue", 0.0}, {"alpha", 255.0}, {"x", 0.0}, {"y", 0.0}, {"z", 0.0}, {"xorigin", 0.0}, {"yorigin", 0.0}, {"angle", 0.0}, {"scale", 1.0}};

    vector<string> parametersName {"display", "size", "color", "dcolor", "position", "dposition", "time", "dtime", "transformation", "signal"};

    /* list of enabled parameters and their state (checked or not). "Display" is always true */
    map<string, bool> parametersList {{"display", true}, {"size", false}, {"color", false}, {"dcolor", false}, {"position", false}, {"dposition", false}, {"time", false}, {"dtime", false}, {"transformation", false}, {"signal", false}};

    bool toCreate;

    // default setup
    vector<string> typesEnabled {"none", "curve", "ellipse", "fastgraph", "file", "gmnf", "grid", "graph", "html", "layer", "line xy" ,      "polygon",       "rect",  "svgf", "txt"};
    vector<string> defaultValues {" ",      " ",     "1. 1.",     " ",     " ",     " ",   "1 1", "mySignal",  " ",  " " ,      "1. 1." ,"0. 0. 1. 1. 0. 1.",  "1. 1.",  "", "\"hello\""};

    // signal
    vector<string> signal {           "y",   "t",   "h",   "s",   "b",   "a" };
    vector<string> signalBufferSize {"200", "200", "200", "200", "200", "200"};
    vector<string> signalValue {     "0.0","0.05", "0.0", "1.0", "1.0", "-1.0"};
};

#endif // INSCOREOBJECT_H
