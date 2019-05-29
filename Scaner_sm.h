//
// ex: set ro:
// DO NOT EDIT.
// generated by smc (http://smc.sourceforge.net/)
// from file : Scaner.sm
//

#ifndef SCANER_SM_H
#define SCANER_SM_H


#define SMC_USES_IOSTREAMS

#include <statemap.h>

// Forward declarations.
class MainMap;
class MainMap_Start;
class MainMap_Name;
class MainMap_Count;
class MainMap_List;
class MainMap_OK;
class MainMap_Error;
class MainMap_Default;
class ScanerState;
class ScanerContext;
class Scaner;

class ScanerState :
    public statemap::State
{
public:

    ScanerState(const char * const name, const int stateId)
    : statemap::State(name, stateId)
    {};

    virtual void Entry(ScanerContext&) {};
    virtual void Exit(ScanerContext&) {};

    virtual void EOS(ScanerContext& context);
    virtual void RESET(ScanerContext& context);
    virtual void close_bracket(ScanerContext& context, char ch);
    virtual void close_scobe(ScanerContext& context, char ch);
    virtual void comma(ScanerContext& context, char ch);
    virtual void digit(ScanerContext& context, char ch);
    virtual void equal(ScanerContext& context, char ch);
    virtual void letter(ScanerContext& context, char ch);
    virtual void minus(ScanerContext& context, char ch);
    virtual void open_bracket(ScanerContext& context, char ch);
    virtual void open_scobe(ScanerContext& context, char ch);
    virtual void space(ScanerContext& context, char ch);
    virtual void unknown(ScanerContext& context);

protected:

    virtual void Default(ScanerContext& context);
};

class MainMap
{
public:

    static MainMap_Start Start;
    static MainMap_Name Name;
    static MainMap_Count Count;
    static MainMap_List List;
    static MainMap_OK OK;
    static MainMap_Error Error;
};

class MainMap_Default :
    public ScanerState
{
public:

    MainMap_Default(const char * const name, const int stateId)
    : ScanerState(name, stateId)
    {};

    virtual void letter(ScanerContext& context, char ch);
    virtual void digit(ScanerContext& context, char ch);
    virtual void space(ScanerContext& context, char ch);
    virtual void comma(ScanerContext& context, char ch);
    virtual void minus(ScanerContext& context, char ch);
    virtual void equal(ScanerContext& context, char ch);
    virtual void open_bracket(ScanerContext& context, char ch);
    virtual void close_bracket(ScanerContext& context, char ch);
    virtual void open_scobe(ScanerContext& context, char ch);
    virtual void close_scobe(ScanerContext& context, char ch);
    virtual void EOS(ScanerContext& context);
    virtual void unknown(ScanerContext& context);
    virtual void RESET(ScanerContext& context);
};

class MainMap_Start :
    public MainMap_Default
{
public:
    MainMap_Start(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void Entry(ScanerContext&);
    virtual void letter(ScanerContext& context, char ch);
    virtual void space(ScanerContext& context, char ch);
};

class MainMap_Name :
    public MainMap_Default
{
public:
    MainMap_Name(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void digit(ScanerContext& context, char ch);
    virtual void letter(ScanerContext& context, char ch);
    virtual void open_scobe(ScanerContext& context, char ch);
};

class MainMap_Count :
    public MainMap_Default
{
public:
    MainMap_Count(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void close_scobe(ScanerContext& context, char ch);
    virtual void digit(ScanerContext& context, char ch);
};

class MainMap_List :
    public MainMap_Default
{
public:
    MainMap_List(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void EOS(ScanerContext& context);
    virtual void close_bracket(ScanerContext& context, char ch);
    virtual void comma(ScanerContext& context, char ch);
    virtual void digit(ScanerContext& context, char ch);
    virtual void equal(ScanerContext& context, char ch);
    virtual void minus(ScanerContext& context, char ch);
    virtual void open_bracket(ScanerContext& context, char ch);
};

class MainMap_OK :
    public MainMap_Default
{
public:
    MainMap_OK(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

    virtual void EOS(ScanerContext& context);
};

class MainMap_Error :
    public MainMap_Default
{
public:
    MainMap_Error(const char * const name, const int stateId)
    : MainMap_Default(name, stateId)
    {};

};

class ScanerContext :
    public statemap::FSMContext
{
public:

    explicit ScanerContext(Scaner& owner)
    : FSMContext(MainMap::Start),
      _owner(owner)
    {};

    ScanerContext(Scaner& owner, const statemap::State& state)
    : FSMContext(state),
      _owner(owner)
    {};

    virtual void enterStartState()
    {
        getState().Entry(*this);
        return;
    }

    inline Scaner& getOwner()
    {
        return (_owner);
    };

    inline ScanerState& getState()
    {
        if (_state == NULL)
        {
            throw statemap::StateUndefinedException();
        }

        return dynamic_cast<ScanerState&>(*_state);
    };

    inline void EOS()
    {
        getState().EOS(*this);
    };

    inline void RESET()
    {
        getState().RESET(*this);
    };

    inline void close_bracket(char ch)
    {
        getState().close_bracket(*this, ch);
    };

    inline void close_scobe(char ch)
    {
        getState().close_scobe(*this, ch);
    };

    inline void comma(char ch)
    {
        getState().comma(*this, ch);
    };

    inline void digit(char ch)
    {
        getState().digit(*this, ch);
    };

    inline void equal(char ch)
    {
        getState().equal(*this, ch);
    };

    inline void letter(char ch)
    {
        getState().letter(*this, ch);
    };

    inline void minus(char ch)
    {
        getState().minus(*this, ch);
    };

    inline void open_bracket(char ch)
    {
        getState().open_bracket(*this, ch);
    };

    inline void open_scobe(char ch)
    {
        getState().open_scobe(*this, ch);
    };

    inline void space(char ch)
    {
        getState().space(*this, ch);
    };

    inline void unknown()
    {
        getState().unknown(*this);
    };

private:
    Scaner& _owner;
};


#endif // SCANER_SM_H

//
// Local variables:
//  buffer-read-only: t
// End:
//
