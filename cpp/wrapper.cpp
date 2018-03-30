#include <nan.h>
#include "analyze.h"

void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
}

void Histogram(const Nan::FunctionCallbackInfo<v8::Value>& info) {

    if (info.Length() <= 0) {
        return;
    }
    v8::String::Utf8Value str(info[0]->ToString());
    std::string filename = std::string(*str);
    Analyze::ReadImage(filename);

    //info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports) {
    exports->Set(Nan::New("hello").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(Method)->GetFunction());
    exports->Set(Nan::New("Histogram").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(Histogram)->GetFunction());
}

NODE_MODULE(hello, Init)
