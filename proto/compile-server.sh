protoc --cpp_out=./apps/server/include/message --proto_path=./proto/message ../proto/message/*
mv ./apps/server/include/message/*.cc ./apps/server/src/message/