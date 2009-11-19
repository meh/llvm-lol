class Token
{
  public:
    enum Type {
        EOF = -1,

        Unknown = 0,

        Dim, As,

        Identifier, Number
    };

  private:
    Type  _type;
    void* _data;

  public:
    Token (void);
    Token (Type type, void* data);

    Type type (void);
    void type (Type type);

    void* data (void);
    void  data (void* data);
};
