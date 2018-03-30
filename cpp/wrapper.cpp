#include <node.h>
#include <opencv2/opencv.hpp>

void HelloFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    v8::Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "hello, world"));
}

void Test(const v8::FunctionCallbackInfo<v8::Value>& args)
{
  cv::Mat m;
    v8::Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "opencv"));
}

void init(v8::Local<v8::Object> exports)
{
    NODE_SET_METHOD(exports, "test", Test);
    NODE_SET_METHOD(exports, "hello", HelloFunction);
}

NODE_MODULE(addon, init);
