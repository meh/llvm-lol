#ifdef _LOL_CORE_PARSER_H

class Token
{
  protected:
    int  _type;
    void* _data;

  public:
    Token (void);
    Token (int type, void* data);

    Type type (void);
    void type (int type);

    void* data (void);
    void  data (void* data);
};

#endif
