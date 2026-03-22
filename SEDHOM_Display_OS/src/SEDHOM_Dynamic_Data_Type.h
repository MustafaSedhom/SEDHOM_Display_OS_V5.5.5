#ifndef SEDHOM_DYNAMIC_DATA_TYPE_H_
#define SEDHOM_DYNAMIC_DATA_TYPE_H_
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
typedef enum 
{
    Data_Type_none,
    Data_Type_char,
    Data_Type_int,
    Data_Type_float,
    Data_Type_double,
    Data_Type_bool,
    Data_Type_string,
}Data_Type_t;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#define max_Dynamic_variable_size_by_byte      50
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
class SEDHOM_Dynamic_Data_Type
{
private:
   Data_Type_t Data_Type;
   union Value
   {
       Value(){}
       char c; 
       int i;
       float f;
       double d;
       bool b;
       char s[max_Dynamic_variable_size_by_byte]; // String
   }value;
public:
    
    SEDHOM_Dynamic_Data_Type();
    SEDHOM_Dynamic_Data_Type(Data_Type_t init_type);
    ~SEDHOM_Dynamic_Data_Type();
    // functions to set Data type for this Dynamic variable
    void set_Data_Type(Data_Type_t type) { Data_Type = type; }
    // functions to get Data type for this Dynamic variable
    Data_Type_t get_Data_Type()  { return Data_Type; }
    // functions to set value for this Dynamic variable
    void set_Value(char val);
    void set_Value(int val);
    void set_Value(float val);
    void set_Value(double val);
    void set_Value(const char* val);
    void set_Value(bool val);
    // functions to can assign value for this Dynamic variable
    SEDHOM_Dynamic_Data_Type& operator=(const SEDHOM_Dynamic_Data_Type& other);
    SEDHOM_Dynamic_Data_Type& operator=(char val);
    SEDHOM_Dynamic_Data_Type& operator=(int val);
    SEDHOM_Dynamic_Data_Type& operator=(float val);
    SEDHOM_Dynamic_Data_Type& operator=(double val);
    SEDHOM_Dynamic_Data_Type& operator=(bool val);
    SEDHOM_Dynamic_Data_Type& operator=(const char* val);
    bool operator==( SEDHOM_Dynamic_Data_Type& other);
    bool operator!=( SEDHOM_Dynamic_Data_Type& other);
    // functions for can change from data type to another
    int    to_Int();
    float  to_Float();
    double to_Double();
    bool   to_Bool();
    char*  to_String();
};

// // =========================
// // Template Specializations
// // =========================
// template<> int DynamicVar::getValue<int>() const { return toInt(); }
// template<> float DynamicVar::getValue<float>() const { return toFloat(); }
// template<> double DynamicVar::getValue<double>() const { return toDouble(); }
// template<> char DynamicVar::getValue<char>() const { return (type == CHAR) ? value.c : '\0'; }
// template<> bool DynamicVar::getValue<bool>() const { return toBool(); }
// template<> const char* DynamicVar::getValue<const char*>() const { return toString(); }
// };
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// define all variables
SEDHOM_Dynamic_Data_Type::SEDHOM_Dynamic_Data_Type()
{
    Data_Type = Data_Type_none;
}
SEDHOM_Dynamic_Data_Type::SEDHOM_Dynamic_Data_Type(Data_Type_t init_type)
{
    Data_Type = init_type;
}
SEDHOM_Dynamic_Data_Type::~SEDHOM_Dynamic_Data_Type()
{
}
void SEDHOM_Dynamic_Data_Type::set_Value(char val)
{
    Data_Type = Data_Type_char ; value.c = val;
}
void SEDHOM_Dynamic_Data_Type::set_Value(int val)
{
    Data_Type = Data_Type_int ; value.i = val;
}
void SEDHOM_Dynamic_Data_Type::set_Value(float val)
{
    Data_Type = Data_Type_float ; value.f = val;
}
void SEDHOM_Dynamic_Data_Type::set_Value(double val)
{
    Data_Type = Data_Type_double ; value.d = val;
}
void SEDHOM_Dynamic_Data_Type::set_Value(bool val)
{
    Data_Type = Data_Type_bool ; value.b = val;
}
void SEDHOM_Dynamic_Data_Type::set_Value(const char* val)
{
    Data_Type = Data_Type_string ;  strncpy(value.s, val, sizeof(value.s));
                value.s[sizeof(value.s)-1] = '\0';
}
SEDHOM_Dynamic_Data_Type& SEDHOM_Dynamic_Data_Type::operator=(const SEDHOM_Dynamic_Data_Type& other)
{
    Data_Type = other.Data_Type;

    switch(Data_Type) {
        case Data_Type_int: value.i = other.value.i; break;
        case Data_Type_float: value.f = other.value.f; break;
        case Data_Type_double: value.d = other.value.d; break;
        case Data_Type_char: value.c = other.value.c; break;
        case Data_Type_bool: value.b = other.value.b; break;
        case Data_Type_string:
            strncpy(value.s, other.value.s, sizeof(value.s));
            value.s[sizeof(value.s)-1] = '\0';
            break;
        default: break;
    }

    return *this;
}
SEDHOM_Dynamic_Data_Type& SEDHOM_Dynamic_Data_Type::operator=(char val) 
{
    set_Value(val);
    return *this;
}
SEDHOM_Dynamic_Data_Type& SEDHOM_Dynamic_Data_Type::operator=(int val) 
{
    set_Value(val);
    return *this;
}
SEDHOM_Dynamic_Data_Type& SEDHOM_Dynamic_Data_Type::operator=(float val) 
{
    set_Value(val);
    return *this;
}
SEDHOM_Dynamic_Data_Type& SEDHOM_Dynamic_Data_Type::operator=(double val) 
{
    set_Value(val);
    return *this;
}
SEDHOM_Dynamic_Data_Type& SEDHOM_Dynamic_Data_Type::operator=(bool val) 
{
    set_Value(val);
    return *this;
}
SEDHOM_Dynamic_Data_Type& SEDHOM_Dynamic_Data_Type::operator=(const char* val) 
{
    set_Value(val);
    return *this;
}
bool SEDHOM_Dynamic_Data_Type::operator==( SEDHOM_Dynamic_Data_Type& other)
{
    if (Data_Type == Data_Type_string || other.Data_Type == Data_Type_string)
    return strcmp(this->to_String(), other.to_String()) == 0;
    return this->to_Double() == other.to_Double();
}
bool SEDHOM_Dynamic_Data_Type::operator!=( SEDHOM_Dynamic_Data_Type& other)
{
    return !(*this == other);
}
int SEDHOM_Dynamic_Data_Type::to_Int() 
{
    switch(Data_Type) 
    {
        case Data_Type_char: return value.c;
        case Data_Type_int: return value.i;
        case Data_Type_float: return (int)value.f;
        case Data_Type_double: return (int)value.d;
        case Data_Type_bool: return value.b ? 1 : 0;
        case Data_Type_string: return atoi(value.s);
        default: return 0;
    }
    
}
float SEDHOM_Dynamic_Data_Type::to_Float() 
{

    switch(Data_Type) 
    {
        case Data_Type_char: return (float)value.c;
        case Data_Type_int: return  (float)value.i;
        case Data_Type_float: return value.f;
        case Data_Type_double: return (float)value.d;
        case Data_Type_bool: return value.b ? 1.0f : 0.0f;
        case Data_Type_string: return atof(value.s);
        default: return 0.0f;
    }
}

double SEDHOM_Dynamic_Data_Type::to_Double() 
{

    switch(Data_Type) 
    {
        case Data_Type_char: return (double)value.c;
        case Data_Type_int: return (double)value.i;
        case Data_Type_float: return (double)value.f;
        case Data_Type_double: return value.d;
        case Data_Type_bool: return value.b ? 1.0 : 0.0;
        case Data_Type_string: return atof(value.s);
        default: return 0.0;
    }
}
bool SEDHOM_Dynamic_Data_Type::to_Bool()  
{
    switch(Data_Type) 
    {
        case Data_Type_int: return value.i != 0;
        case Data_Type_float: return value.f != 0;
        case Data_Type_double: return value.d != 0;
        case Data_Type_bool: return value.b;
        case Data_Type_string: return strcmp(value.s,"true") == 0;
        default: return false;
    }
}

char* SEDHOM_Dynamic_Data_Type::to_String() 
{
    char buffer[50];
    switch(Data_Type)
    {
        case Data_Type_int:    snprintf(buffer, sizeof(buffer), "%d", value.i); break;
        case Data_Type_float:  snprintf(buffer, sizeof(buffer), "%.2f", value.f); break;
        case Data_Type_double: snprintf(buffer, sizeof(buffer), "%.2lf", value.d); break;
        case Data_Type_char:   snprintf(buffer, sizeof(buffer), "%c", value.c); break;
        case Data_Type_bool:   snprintf(buffer, sizeof(buffer), "%s", value.b ? "true" : "false"); break;
        case Data_Type_string: return value.s;
        default: return "";
    }
    return buffer;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#endif // !SEDHOM_DYNAMIC_DATA_TYPE_H_