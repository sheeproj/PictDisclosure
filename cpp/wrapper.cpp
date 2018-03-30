#include <node.h>

void HelloFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    v8::Isolate* isolate = args.GetIsolate();
    // 返り値を設定
    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "hello, world"));
}

void init(v8::Local<v8::Object> exports)
{
    // hello 関数を外部に公開
    NODE_SET_METHOD(exports, "hello", HelloFunction);
}

NODE_MODULE(my_extension, init);
