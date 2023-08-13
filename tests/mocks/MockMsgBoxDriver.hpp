#pragma once

#include <expected>
#include <system_error>

#include <trompeloeil.hpp>

#include <geecore/MsgBoxPrimitives.hpp>
#include <geecore/drivers/IMsgBoxDriver.hpp>

namespace geecore::tests
{
template<typename T>
class MockMsgBoxDriver : public geecore::IMsgBoxDriver<T>
{
public:
    MAKE_CONST_MOCK4(show,
                     (std::expected<MsgBoxSelection, std::error_code>(geecore::MsgBoxIcon icon,
                                                                      const T* title,
                                                                      const T* text,
                                                                      geecore::MsgBoxButtons buttons)),
                     noexcept);
};
} // namespace geecore::tests
