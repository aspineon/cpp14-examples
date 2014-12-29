#include "gtest/gtest.h"
#include <tuple>
#include <complex>

/**
 * Recursively define tuple_to_stream with std::enable_if
 * when I == sizeof...(Tp)
 */
template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), std::ostringstream&>::type
  tuple_to_stream(std::tuple<Tp...>& t, std::ostringstream& out)
  {
    out << ")";
    return out;
  }

/**
 * when I < sizeof...(Tp)
 */
template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), std::ostringstream&>::type
  tuple_to_stream(std::tuple<Tp...>& t, std::ostringstream& out)
  {
    if (I == 0) {
      out << "(";
    }
    out << std::get<I>(t);
    if (I != sizeof...(Tp) - 1) {
      out << ", ";
    }
    tuple_to_stream<I + 1, Tp...>(t, out);
    return out;
  }

/**
 * Example usage of std::enable_if
 * It is generically convert a tuple into a stringstream.
 */
TEST(ENABLE_IF_TEST, recursive_test) {
  auto t1 = std::make_tuple(1, 1.2, "foo");
  std::ostringstream s1;
  EXPECT_EQ("(1, 1.2, foo)", tuple_to_stream(t1, s1).str());

  using namespace std::literals;
  std::ostringstream s2;
  auto t2 = std::make_tuple("bar", 4L, -1.03, 1. + 2i);
  EXPECT_EQ("(bar, 4, -1.03, (1,2))", tuple_to_stream(t2, s2).str());

}
