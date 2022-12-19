#include "queue.h"
#include <gtest.h>

TEST(Queue, cant_create_queue_more_than_MAX_SIZE_QUEUE)
{
	ASSERT_ANY_THROW(Queue<int> v(MAX_SIZE_QUEUE+1));
}

TEST(Queue, cant_create_queue_less_than_MIN_SIZE_QUEUE)
{
	
	ASSERT_ANY_THROW(Queue<int> v(MIN_SIZE_QUEUE - 1));
}
 
TEST(Queue, can_create_queue_with_size_MAX_SIZE_QUEUE)
{
	ASSERT_NO_THROW(Queue<int> v(MAX_SIZE_QUEUE));
}

TEST(Queue, can_create_queue_with_size_MIN_SIZE_QUEUE)
{
	ASSERT_NO_THROW(Queue<int> v(MIN_SIZE_QUEUE));
}

TEST(Queue, can_get_size_of_queue)
{
	Queue<int> v(10);
	EXPECT_EQ(10, v.getSize());

}

TEST(Queue, can_get_first_in_queue)
{
	Queue<int> v(10);
	v.push(12);
	v.push(13131);
	EXPECT_EQ(12, v.get());
}

TEST(Queue, check_queue_is_empty)
{
	Queue<int> v(10);
	EXPECT_EQ(1, v.isEmpty());
}

TEST(Queue, check_queue_is_not_empty)
{
	Queue<int> v(10);
	v.push(5);
	EXPECT_EQ(0, v.isEmpty());
}

TEST(Queue, check_queue_is_full)
{
	Queue<int> v(5);
	v.push(10);
	v.push(10);
	v.push(10);
	v.push(10);
	v.push(10);
	EXPECT_EQ(true, v.isFull());
}

TEST(Queue, can_count_element_in_queue)
{
	Queue<int> v(50);
	v.push(10);
	v.push(10);
	v.push(10);
	v.push(10);
	EXPECT_EQ(4, v.count());
}

TEST(Queue, can_get_element_from_queue)
{
	Queue<int> v(50);
	v.push(10);
	v.push(10);
	v.push(10);
	v.push(10);
	EXPECT_EQ(4, v.count());
}

TEST(Queue, get_cant_change_queue)
{
	Queue<int> v(5);
	v.push(10);
	v.push(15);
	v.push(10);
	v.push(15);
	v.push(10);
	int _v = v.get();
	EXPECT_EQ(10, v.get());
}
