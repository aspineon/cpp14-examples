#include "gtest/gtest.h"

/**
 * An example struct that inherits enable_shared_from_this.
 */
struct SharedPtrDemo : public std::enable_shared_from_this<SharedPtrDemo> {
};

/**
 * When SharedPtrDemo is declared as shared_ptr
 * will shared_from_this() works as expected.
 * shared_from_this() is normally invoked within the class.
 */
TEST(SHARED_PTR_TEST, enable_shared_from_this_test) {
  std::shared_ptr<SharedPtrDemo> p(new SharedPtrDemo);
  EXPECT_EQ(p, p->shared_from_this());
}

/**
 * If SharedPtrDemo is not declared as shared_ptr,
 * shared_from_this() would throw an std::exception
 */
TEST(SHARED_PTR_TEST, enable_shared_not_shared_ptr) {
  SharedPtrDemo d;
  SharedPtrDemo* pd = &d;
  EXPECT_THROW(pd->shared_from_this(), std::exception);
}

/**
 * weak_ptr will not increase the ref count.
 * unless it is accessing the pointer by lock()
 */
TEST(SHARED_PTR_TEST, weak_ptr_test) {
  std::shared_ptr<SharedPtrDemo> p(new SharedPtrDemo);
  std::weak_ptr<SharedPtrDemo> wp(p);
  EXPECT_EQ(1, p.use_count());
  // trying to access weak_ptr by lock()
  auto t = wp.lock();
  EXPECT_NE(nullptr, t.get());
  // after lock(), it gets a shared_ptr
  EXPECT_TRUE((std::is_same<std::shared_ptr<SharedPtrDemo>, decltype(t)>::value));
  // They are managing the same pointer.
  EXPECT_EQ(t.get(), p.get());
  // and now the ref count increases;
  EXPECT_EQ(2, p.use_count());

  // reset shared pointers
  t.reset();
  p.reset();

  EXPECT_EQ(0, p.use_count());
  t = wp.lock();
  EXPECT_EQ(nullptr, t.get());
}