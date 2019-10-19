#pragma once

#include "ll.h"

/** Forward declaration */
struct workqueue_unit;

/**
 * Function prototype for a workqueue callback function
 * @param[out] wq_unit the @ref workqueue_unit which was used when registering the work
 * @param[out] ctxt The user context provided during registration of the work unit
 */
typedef void (*workqueue_cb)(struct workqueue_unit *wq_unit, void *ctxt);

/**
 * A unit of work
 */
struct workqueue_unit {
    struct ll_node node;  /**< Linked-list node which is used internally. */
    workqueue_cb cb;      /**< User callback. */
    void *ctxt;           /**< User context. */
};

/**
 * Intialize the workqueue context
 */
void workqueue_init(void);

/**
 * Add a unit of work.
 * @note If you are re-using wq_unit's (@ref workqueue_unit),
 *       keep in mind that if the work associated with the wq_unit is not done,
 *       this function will return an error if you try to add the wq_unit.
 *
 * @param[in] wq_unit
 * @param[in] work_cb
 * @param[in] ctxt
 *
 * @return An errorcode
 * @retval 0 if the work was added
 * @retval < 0 if the work could not be added (bad params...)
 */
int workqueue_add_work(struct workqueue_unit *wq_unit, workqueue_cb work_cb, void *ctxt);

/**
 * Do one unit of work
 */
void workqueue_do_work(void);

/**
 * Check if there is work pending
 *
 * @return bool flag indicating if work is pending
 * @retval true if there is work to do
 * @retval false if there is no more work to do
 */
bool workqueue_is_work_pending(void);

/**
 * Deintialize the workqueue context
 */
void workqueue_deinit(void);
