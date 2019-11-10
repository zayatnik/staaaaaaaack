#include "utmatrix.h"
#include <gtest.h>


TEST(stack, can_create_standart_stack) {
	ASSERT_NO_THROW(stack<int> v);
}

TEST(stack, can_push) {
	stack<int> s;
	s.push(10);
	EXPECT_EQ(s.onthetop(), 10);
}

TEST(stack, can_get_size) {
	stack<int> s;
	s.push(10);
	EXPECT_EQ(s.size(), 1);
}

TEST(stack, can_copy) {
	stack<int> s;
	ASSERT_NO_THROW(stack<int> s1(s));
}

TEST(stack, the_copied_stack_has_its_own_memory) {
	stack<int> s;
	s.push(3);
	stack<int> s1(s);
	s1.push(4);
	EXPECT_FALSE(s.onthetop() == s1.onthetop());
}

TEST(stack, the_copied_stack_is_equal_with_original) {
	stack<int> s;
	s.push(10);
	stack<int> s1(s);
	EXPECT_TRUE(s == s1);
}

TEST(stack, can_pop) {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.pop();
	EXPECT_EQ(s.onthetop(), 1);
}

TEST(stack, throws_when_set_el_from_pust_stack) {
	stack<int> s;
	ASSERT_ANY_THROW(s.onthetop());
}

TEST(stack, throws_when_delete_el_from_pust_stack) {
	stack<int> s;
	ASSERT_ANY_THROW(s.pop());
}

////