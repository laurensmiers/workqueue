#include "unity.h"
#include "workqueue.h"

#include "mock_workqueue_helper.h"

TEST_FILE("ll.c")

void setUp(void)
{
	workqueue_init();
}

void tearDown(void)
{
	workqueue_deinit();
}

void test_add_work(void)
{
	struct workqueue_unit wq_unit = { 0 };

	TEST_ASSERT_FALSE(workqueue_is_work_pending());

	workqueue_add_work(&wq_unit, dummy_work_cb_0, (void *)1234);

	TEST_ASSERT(workqueue_is_work_pending());

	dummy_work_cb_0_Expect(&wq_unit, (void *)1234);

	workqueue_do_work();
}
