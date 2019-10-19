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
	wq_unit->cb = work_cb;
	wq_unit->ctxt = ctxt;

	return ll_push_to_tail(&_ctxt.work_list, &wq_unit->node);
}

void workqueue_do_work(void)
{
	struct workqueue_unit *work = (struct workqueue_unit *)ll_get_head(&_ctxt.work_list);

	if (!work)
		return;

	ll_remove_node(&work->node);

	work->cb(work, work->ctxt);
}

bool workqueue_is_work_pending(void)
{
	return !ll_is_empty(&_ctxt.work_list);
}

void workqueue_deinit(void)
{
	ll_deinit(&_ctxt.work_list);
}
