#pragma once
#include <curl/curl.h>

#include <functional>
#include <iostream>
#include <memory>

typedef size_t (*WriteCbType)(void* ptr, size_t size, size_t nmemb, void* stream ); 
namespace cu {
  namespace funcs{
  size_t write_cb(void* ptr, size_t size, size_t nmemb, void* stream) {
    size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
    return written;
  }
  }
class Curl {
 public:
  Curl() {
    curl_global_init(CURL_GLOBAL_ALL);
    InitIfNot();
  }
  ~Curl() {
    std::cout << "~Curl" << std::endl;
    curl_easy_cleanup(curl_); }
  CURLcode Run(){
    return curl_easy_perform(curl_);
  }
  void SetUrl(const char*& url) { 
    std::cout<<curl_<<std::endl;
    
    curl_easy_setopt(curl_, CURLOPT_URL, url); }
  void SetWriteFunction(WriteCbType cb) {
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION,cb);
  }
  void SetWriteData(const FILE* fp) {
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, fp);
  }

 private:
  bool InitIfNot() {
    if (curl_ != nullptr) {
      return true;
    } else {
      curl_ = curl_easy_init();
    std::cout<<curl_<<std::endl;

    }
    if (curl_ != nullptr) {
      return true;
    }
    return false;
  }
  CURL* curl_{nullptr};
};

class CurlUtils {
 public:
  static bool Download(const char*& url, const char*& file_path,
                       std::shared_ptr<Curl> sp_curl = nullptr) {
    std::shared_ptr<Curl> sp_curl_temp = sp_curl;
    if (sp_curl_temp == nullptr) {
      sp_curl_temp = std::make_shared<Curl>();
    }
    sp_curl_temp->SetUrl(url);
    FILE* fp = fopen(file_path, "wb");
    sp_curl_temp->SetWriteFunction(funcs::write_cb);
    sp_curl_temp->SetWriteData(fp);
    auto res = sp_curl_temp->Run();
    fclose(fp);
    return res;
  }
};

}  // namespace cu
