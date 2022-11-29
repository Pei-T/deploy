#pragma once
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/parameter.hpp>
#include <rcl_interfaces/msg/set_parameters_result.hpp>
#include <string>
#include <memory>
using OnChangeCallback=std::function<void(const std::vector<rclcpp::Parameter>)>;
namespace sp {

class Ros2ParameterService : public rclcpp::Node {
 public:
  Ros2ParameterService(std::string node_name) : Node(node_name) {
    sp_node_=rclcpp::Node::SharedPtr(this);
    rclcpp::spin_some(sp_node_);
  }
  template<typename T>
  void Set(std::string key,T value){
    if(!has_parameter(key)){
      declare_parameter<T>(key,value);
      return;
    }
    rclcpp::Parameter tmp(key,value);
    set_parameter(tmp);
  }
  template<typename T>
  T Get(std::string key){
    T res;
    get_parameter<T>(key,res);
    return res;
  }
  void OnChange(OnChangeCallback cb){
    on_change_cb_=cb;
    callback_handle_=add_on_set_parameters_callback(
    std::bind(&Ros2ParameterService::ParametersCallback, this, std::placeholders::_1));

  }
 private:
  rclcpp::Node::SharedPtr sp_node_;
  std::function<void(const std::vector<rclcpp::Parameter>)>on_change_cb_;
  OnSetParametersCallbackHandle::SharedPtr callback_handle_;
  rcl_interfaces::msg::SetParametersResult ParametersCallback(
    const std::vector<rclcpp::Parameter> &parameters) {
    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;
    result.reason = "success";
    on_change_cb_(parameters);
    return result;
  }
};
std::shared_ptr<Ros2ParameterService> MakeParameterServer(std::string node_name){
  const char* tmp[]={"unused"};
  rclcpp::init(1,tmp);
  return std::make_shared<Ros2ParameterService>(node_name);
}
}  // namespace sp
