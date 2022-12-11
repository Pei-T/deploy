#include <sys/epoll.h>

#include <array>
#include <vector>

class Epoll {
public:
  // Constructor
  Epoll() : epoll_fd_(epoll_create1(0)) {}

  // Destructor
  ~Epoll() {
    close(epoll_fd_);
  }

  // Add a file descriptor to the set monitored by epoll
  void add(int fd) {
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, fd, &event);
  }

  // Remove a file descriptor from the set monitored by epoll
  void remove(int fd) {
    epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, fd, nullptr);
  }

  // Wait for events on the monitored file descriptors
  std::vector<int> wait() {
    std::array<struct epoll_event, 128> events;
    int n = epoll_wait(epoll_fd_, events.data(), events.size(), -1);
    std::vector<int> ready_fds;
    for (int i = 0; i < n; i++) {
      ready_fds.push_back(events[i].data.fd);
    }
    return ready_fds;
  }

private:
  int epoll_fd_;
};
