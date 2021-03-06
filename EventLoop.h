#include "boost/noncopyable.hpp"
#include<sched.h>
#include<thread>
//#include <linux/unistd.h>
//#include<pthread_np.h>
#include "unistd.h"


#ifndef  SUNSQ_EVENTLOOP_H
#define SUNSQ_EVENTLOOP_H

namespace SUNSQ{
class EventLoop : boost :: noncopyable{
    public:
        EventLoop();
        ~EventLoop();

        void loop();

        void assertInLoopThread(){
            if(!isInLoopThread())
            {
                abortNotInLoopThread();
            }
        }

        bool isInLoopThread() const{
            pid_t id = getpid();
            //pid_t thisId = std::pthread_np::pthread_getthreadid_np();
            return threadId_ == id;
            //std::thread::id tid = std::this_thread::get_id();
        }

        EventLoop* getEventLoopOfCurrentThread();

    private:
        void abortNotInLoopThread();

        bool looping_;
        const pid_t threadId_;

};

}


#endif // SUNSQ_EVENTLOOP_H




