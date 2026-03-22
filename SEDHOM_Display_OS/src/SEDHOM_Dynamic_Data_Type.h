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
       char s[50]; // String
   }value;
public:
    
    SEDHOM_Dynamic_Data_Type();
    ~SEDHOM_Dynamic_Data_Type();
    // functions to get Data type for this Dynamic variable
    void set_Type(Data_Type_t type) { Data_Type = type; }
    // functions to get Data type for this Dynamic variable
    Data_Type_t get_Type()  { return Data_Type; }
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
};
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// define all variables
SEDHOM_Dynamic_Data_Type::SEDHOM_Dynamic_Data_Type()
{
    Data_Type = Data_Type_none;
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
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#endif // !SEDHOM_DYNAMIC_DATA_TYPE_H_