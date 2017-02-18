#ifndef QUEUE_MANAGER_H
#define QUEUE_MANAGER_H

#include <Queue.h>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

class QueueManager {
 public:
  QueueManager();
  std::shared_ptr<Queue> queueInit(std::string name, std::string bindingKey,
                                   bool persistence, bool durability);
  void publish(std::string routing_key, std::vector<uint8_t> message);

 private:
  std::unordered_map<std::string, std::shared_ptr<Queue> > _queues;
  std::mutex _mutex;
};

extern QueueManager manager;

#endif  // QUEUE_MANAGER_H