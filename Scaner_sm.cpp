//
// ex: set ro:
// DO NOT EDIT.
// generated by smc (http://smc.sourceforge.net/)
// from file : Scaner.sm
//

#include "Scaner.h"
#include "Scaner_sm.h"

using namespace statemap;

// Static class declarations.
MainMap_Start MainMap::Start("MainMap::Start", 0);
MainMap_Name MainMap::Name("MainMap::Name", 1);
MainMap_Count MainMap::Count("MainMap::Count", 2);
MainMap_List MainMap::List("MainMap::List", 3);
MainMap_OK MainMap::OK("MainMap::OK", 4);
MainMap_Error MainMap::Error("MainMap::Error", 5);

void ScanerState::EOS(ScanerContext& context)
{
    Default(context);
}

void ScanerState::RESET(ScanerContext& context)
{
    Default(context);
}

void ScanerState::close_bracket(ScanerContext& context, char ch)
{
    Default(context);
}

void ScanerState::close_scobe(ScanerContext& context, char ch)
{
    Default(context);
}

void ScanerState::comma(ScanerContext& context, char ch)
{
    Default(context);
}

void ScanerState::digit(ScanerContext& context, char ch)
{
    Default(context);
}

void ScanerState::equal(ScanerContext& context, char ch)
{
    Default(context);
}

void ScanerState::letter(ScanerContext& context, char ch)
{
    Default(context);
}

void ScanerState::minus(ScanerContext& context, char ch)
{
    Default(context);
}

void ScanerState::open_bracket(ScanerContext& context, char ch)
{
    Default(context);
}

void ScanerState::open_scobe(ScanerContext& context, char ch)
{
    Default(context);
}

void ScanerState::space(ScanerContext& context, char ch)
{
    Default(context);
}

void ScanerState::unknown(ScanerContext& context)
{
    Default(context);
}

void ScanerState::Default(ScanerContext& context)
{
    throw (
        TransitionUndefinedException(
            context.getState().getName(),
            context.getTransition()));

}

void MainMap_Default::letter(ScanerContext& context, char ch)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::digit(ScanerContext& context, char ch)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::space(ScanerContext& context, char ch)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::comma(ScanerContext& context, char ch)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::minus(ScanerContext& context, char ch)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::equal(ScanerContext& context, char ch)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::open_bracket(ScanerContext& context, char ch)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::close_bracket(ScanerContext& context, char ch)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::open_scobe(ScanerContext& context, char ch)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::close_scobe(ScanerContext& context, char ch)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::EOS(ScanerContext& context)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::unknown(ScanerContext& context)
{

    context.getState().Exit(context);
    context.setState(MainMap::Error);
    context.getState().Entry(context);

}

void MainMap_Default::RESET(ScanerContext& context)
{
    Scaner& ctxt = context.getOwner();

    context.getState().Exit(context);
    context.clearState();
    try
    {
        ctxt.reset_all();
        context.setState(MainMap::Start);
    }
    catch (...)
    {
        context.setState(MainMap::Start);
        throw;
    }
    context.getState().Entry(context);

}

void MainMap_Start::Entry(ScanerContext& context)

{
    Scaner& ctxt = context.getOwner();

    ctxt.reset_all();
}

void MainMap_Start::letter(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    ScanerState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.buffer.append(1, ch);
        ctxt.inc_len();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }

}

void MainMap_Start::space(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    if (ctxt.chk_is_type())
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.len_and_buf_reset();
            ctxt.buffer.append(1, ch);
            ctxt.inc_len();
            context.setState(MainMap::Name);
        }
        catch (...)
        {
            context.setState(MainMap::Name);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::space(context, ch);
    }

}

void MainMap_Name::digit(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    if (ctxt.chk_len())
    {
        ScanerState& endState = context.getState();

        context.clearState();
        try
        {
            ctxt.buffer.append(1, ch);
            ctxt.inc_len();
            context.setState(endState);
        }
        catch (...)
        {
            context.setState(endState);
            throw;
        }
    }
    else
    {
         MainMap_Default::digit(context, ch);
    }

}

void MainMap_Name::letter(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    if (ctxt.chk_len())
    {
        ScanerState& endState = context.getState();

        context.clearState();
        try
        {
            ctxt.buffer.append(1, ch);
            ctxt.inc_len();
            context.setState(endState);
        }
        catch (...)
        {
            context.setState(endState);
            throw;
        }
    }
    else
    {
         MainMap_Default::letter(context, ch);
    }

}

void MainMap_Name::open_scobe(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    if (ctxt.chk_is_name())
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.getConflict();
            ctxt.len_and_buf_reset();
            ctxt.buffer.append(1, ch);
            ctxt.inc_len();
            context.setState(MainMap::Count);
        }
        catch (...)
        {
            context.setState(MainMap::Count);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::open_scobe(context, ch);
    }

}

void MainMap_Count::close_scobe(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    context.getState().Exit(context);
    context.clearState();
    try
    {
        ctxt.getNumber();
        ctxt.len_and_buf_reset();
        ctxt.buffer.append(1, ch);
        ctxt.inc_len();
        context.setState(MainMap::List);
    }
    catch (...)
    {
        context.setState(MainMap::List);
        throw;
    }
    context.getState().Entry(context);

}

void MainMap_Count::digit(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    if (ctxt.chk_count_len())
    {
        ScanerState& endState = context.getState();

        context.clearState();
        try
        {
            ctxt.buffer.append(1, ch);
            ctxt.inc_len();
            context.setState(endState);
        }
        catch (...)
        {
            context.setState(endState);
            throw;
        }
    }
    else
    {
         MainMap_Default::digit(context, ch);
    }

}

void MainMap_List::EOS(ScanerContext& context)
{
    Scaner& ctxt = context.getOwner();

    if (ctxt.chk_is_list())
    {
        context.getState().Exit(context);
        context.clearState();
        try
        {
            ctxt.Right();
            context.setState(MainMap::OK);
        }
        catch (...)
        {
            context.setState(MainMap::OK);
            throw;
        }
        context.getState().Entry(context);
    }
    else
    {
         MainMap_Default::EOS(context);
    }

}

void MainMap_List::close_bracket(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    ScanerState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.buffer.append(1, ch);
        ctxt.inc_len();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }

}

void MainMap_List::comma(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    if (ctxt.chk_comma())
    {
        ScanerState& endState = context.getState();

        context.clearState();
        try
        {
            ctxt.buffer.append(1, ch);
            ctxt.inc_len();
            ctxt.inc_CommaNumber();
            context.setState(endState);
        }
        catch (...)
        {
            context.setState(endState);
            throw;
        }
    }
    else
    {
         MainMap_Default::comma(context, ch);
    }

}

void MainMap_List::digit(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    ScanerState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.buffer.append(1, ch);
        ctxt.inc_len();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }

}

void MainMap_List::equal(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    ScanerState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.buffer.append(1, ch);
        ctxt.inc_len();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }

}

void MainMap_List::minus(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    if (ctxt.chk_minus())
    {
        ScanerState& endState = context.getState();

        context.clearState();
        try
        {
            ctxt.buffer.append(1, ch);
            ctxt.inc_len();
            context.setState(endState);
        }
        catch (...)
        {
            context.setState(endState);
            throw;
        }
    }
    else
    {
         MainMap_Default::minus(context, ch);
    }

}

void MainMap_List::open_bracket(ScanerContext& context, char ch)
{
    Scaner& ctxt = context.getOwner();

    ScanerState& endState = context.getState();

    context.clearState();
    try
    {
        ctxt.buffer.append(1, ch);
        ctxt.inc_len();
        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }

}

void MainMap_OK::EOS(ScanerContext& context)
{


}

//
// Local variables:
//  buffer-read-only: t
// End:
//