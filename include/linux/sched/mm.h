#ifndef _LINUX_SCHED_MM_H
#define _LINUX_SCHED_MM_H

#include <linux/sched.h>
#include <linux/mm_types.h>
#include <linux/gfp.h>

/*
 * Routines for handling mm_structs
 */
extern struct mm_struct * mm_alloc(void);

/* mmdrop drops the mm and the page tables */
extern void __mmdrop(struct mm_struct *);
static inline void mmdrop(struct mm_struct *mm)
{
	if (unlikely(atomic_dec_and_test(&mm->mm_count)))
		__mmdrop(mm);
}

static inline bool mmget_not_zero(struct mm_struct *mm)
{
	return atomic_inc_not_zero(&mm->mm_users);
}

/* mmput gets rid of the mappings and all user-space */
extern int mmput(struct mm_struct *);
/* same as above but performs the slow path from the async kontext. Can
 * be called from the atomic context as well
 */
extern void mmput_async(struct mm_struct *);

/* Grab a reference to a task's mm, if it is not already going away */
extern struct mm_struct *get_task_mm(struct task_struct *task);
/*
 * Grab a reference to a task's mm, if it is not already going away
 * and ptrace_may_access with the mode parameter passed to it
 * succeeds.
 */
extern struct mm_struct *mm_access(struct task_struct *task, unsigned int mode);
/* Remove the current tasks stale references to the old mm_struct on exit() */
extern void exit_mm_release(struct task_struct *, struct mm_struct *);
/* Remove the current tasks stale references to the old mm_struct on exec() */
extern void exec_mm_release(struct task_struct *, struct mm_struct *);

#ifdef CONFIG_MEMCG
extern void mm_update_next_owner(struct mm_struct *mm);
#else
static inline void mm_update_next_owner(struct mm_struct *mm)
{
}
#endif /* CONFIG_MEMCG */

#ifdef CONFIG_MMU
extern void arch_pick_mmap_layout(struct mm_struct *mm);
extern unsigned long
arch_get_unmapped_area(struct file *, unsigned long, unsigned long,
		       unsigned long, unsigned long);
extern unsigned long
arch_get_unmapped_area_topdown(struct file *filp, unsigned long addr,
			  unsigned long len, unsigned long pgoff,
			  unsigned long flags);
#else
static inline void arch_pick_mmap_layout(struct mm_struct *mm) {}
#endif

#endif /* _LINUX_SCHED_MM_H */
