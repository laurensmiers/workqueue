#include "workqueue.h"

struct workqueue_ctxt {
	struct ll_node work_list;
};

struct workqueue_ctxt _ctxt = { 0 };

void workqueue_init(void)
{
	ll_init(&_ctxt.work_list);
}

int workqueue_add_work(struct workqueue_unit *wq_unit, workqueue_cb work_cb, void *ctxt)
{
	(void)wq_unit;
	(void)work_cb;
	(void)ctxt;

	return -1;
}

void workqueue_do_work(void)
{
}

bool workqueue_is_work_pending(void)
{
	return false;
}

void workqueue_deinit(void)
{
}
