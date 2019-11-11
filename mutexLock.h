/*
 * mutexLock.h
 *
 * Author: Serena Cheng
 */

#ifndef TEMPLATE_FILES_MUTEXLOCK_H_
#define TEMPLATE_FILES_MUTEXLOCK_H_

class mutexLock {

	public:

		mutexLock();
		virtual ~mutexLock();

		bool acquire();
		void release();

	private:

		bool isAvailable;

};

#endif /* MUTEXLOCK_H_ */
