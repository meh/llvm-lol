#ifdef _LOL_CORE_PARSER_H

class Token
{
  public:
    typedef int Type;

  public:
    enum Types {
        Unknown = 0,

        Version
    };

  protected:
    unsigned _line;

    int   _type;
    void* _data;

  public:
    Token (void);
    Token (Type type, void* data, unsigned line = 0);

    virtual ~Token (void);

    Type type (void);
    void type (Type type);

    void* data (void);
    void  data (void* data);
};

#endif
