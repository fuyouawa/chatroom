// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: send_msg_to_friend.proto

#include "send_msg_to_friend.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace chatroom {
namespace msgpb {
class SendMsgToFriendDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<SendMsgToFriend> _instance;
} _SendMsgToFriend_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
static void InitDefaultsscc_info_SendMsgToFriend_send_5fmsg_5fto_5ffriend_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::chatroom::msgpb::_SendMsgToFriend_default_instance_;
    new (ptr) ::chatroom::msgpb::SendMsgToFriend();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::chatroom::msgpb::SendMsgToFriend::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SendMsgToFriend_send_5fmsg_5fto_5ffriend_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_SendMsgToFriend_send_5fmsg_5fto_5ffriend_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_send_5fmsg_5fto_5ffriend_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_send_5fmsg_5fto_5ffriend_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_send_5fmsg_5fto_5ffriend_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_send_5fmsg_5fto_5ffriend_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::SendMsgToFriend, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::SendMsgToFriend, user_id_),
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::SendMsgToFriend, friend_id_),
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::SendMsgToFriend, msg_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::chatroom::msgpb::SendMsgToFriend)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::chatroom::msgpb::_SendMsgToFriend_default_instance_),
};

const char descriptor_table_protodef_send_5fmsg_5fto_5ffriend_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\030send_msg_to_friend.proto\022\016chatroom.msg"
  "pb\"B\n\017SendMsgToFriend\022\017\n\007user_id\030\001 \001(\005\022\021"
  "\n\tfriend_id\030\002 \001(\005\022\013\n\003msg\030\003 \001(\tb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_send_5fmsg_5fto_5ffriend_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_send_5fmsg_5fto_5ffriend_2eproto_sccs[1] = {
  &scc_info_SendMsgToFriend_send_5fmsg_5fto_5ffriend_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_send_5fmsg_5fto_5ffriend_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_send_5fmsg_5fto_5ffriend_2eproto = {
  false, false, descriptor_table_protodef_send_5fmsg_5fto_5ffriend_2eproto, "send_msg_to_friend.proto", 118,
  &descriptor_table_send_5fmsg_5fto_5ffriend_2eproto_once, descriptor_table_send_5fmsg_5fto_5ffriend_2eproto_sccs, descriptor_table_send_5fmsg_5fto_5ffriend_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_send_5fmsg_5fto_5ffriend_2eproto::offsets,
  file_level_metadata_send_5fmsg_5fto_5ffriend_2eproto, 1, file_level_enum_descriptors_send_5fmsg_5fto_5ffriend_2eproto, file_level_service_descriptors_send_5fmsg_5fto_5ffriend_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_send_5fmsg_5fto_5ffriend_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_send_5fmsg_5fto_5ffriend_2eproto)), true);
namespace chatroom {
namespace msgpb {

// ===================================================================

void SendMsgToFriend::InitAsDefaultInstance() {
}
class SendMsgToFriend::_Internal {
 public:
};

SendMsgToFriend::SendMsgToFriend(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:chatroom.msgpb.SendMsgToFriend)
}
SendMsgToFriend::SendMsgToFriend(const SendMsgToFriend& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_msg().empty()) {
    msg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_msg(),
      GetArena());
  }
  ::memcpy(&user_id_, &from.user_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&friend_id_) -
    reinterpret_cast<char*>(&user_id_)) + sizeof(friend_id_));
  // @@protoc_insertion_point(copy_constructor:chatroom.msgpb.SendMsgToFriend)
}

void SendMsgToFriend::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_SendMsgToFriend_send_5fmsg_5fto_5ffriend_2eproto.base);
  msg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&user_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&friend_id_) -
      reinterpret_cast<char*>(&user_id_)) + sizeof(friend_id_));
}

SendMsgToFriend::~SendMsgToFriend() {
  // @@protoc_insertion_point(destructor:chatroom.msgpb.SendMsgToFriend)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void SendMsgToFriend::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  msg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void SendMsgToFriend::ArenaDtor(void* object) {
  SendMsgToFriend* _this = reinterpret_cast< SendMsgToFriend* >(object);
  (void)_this;
}
void SendMsgToFriend::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void SendMsgToFriend::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const SendMsgToFriend& SendMsgToFriend::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_SendMsgToFriend_send_5fmsg_5fto_5ffriend_2eproto.base);
  return *internal_default_instance();
}


void SendMsgToFriend::Clear() {
// @@protoc_insertion_point(message_clear_start:chatroom.msgpb.SendMsgToFriend)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  msg_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::memset(&user_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&friend_id_) -
      reinterpret_cast<char*>(&user_id_)) + sizeof(friend_id_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SendMsgToFriend::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 user_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          user_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 friend_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          friend_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string msg = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_msg();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "chatroom.msgpb.SendMsgToFriend.msg"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* SendMsgToFriend::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:chatroom.msgpb.SendMsgToFriend)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 user_id = 1;
  if (this->user_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_user_id(), target);
  }

  // int32 friend_id = 2;
  if (this->friend_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_friend_id(), target);
  }

  // string msg = 3;
  if (this->msg().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_msg().data(), static_cast<int>(this->_internal_msg().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "chatroom.msgpb.SendMsgToFriend.msg");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:chatroom.msgpb.SendMsgToFriend)
  return target;
}

size_t SendMsgToFriend::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:chatroom.msgpb.SendMsgToFriend)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string msg = 3;
  if (this->msg().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_msg());
  }

  // int32 user_id = 1;
  if (this->user_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_user_id());
  }

  // int32 friend_id = 2;
  if (this->friend_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_friend_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SendMsgToFriend::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:chatroom.msgpb.SendMsgToFriend)
  GOOGLE_DCHECK_NE(&from, this);
  const SendMsgToFriend* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SendMsgToFriend>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:chatroom.msgpb.SendMsgToFriend)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:chatroom.msgpb.SendMsgToFriend)
    MergeFrom(*source);
  }
}

void SendMsgToFriend::MergeFrom(const SendMsgToFriend& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:chatroom.msgpb.SendMsgToFriend)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.msg().size() > 0) {
    _internal_set_msg(from._internal_msg());
  }
  if (from.user_id() != 0) {
    _internal_set_user_id(from._internal_user_id());
  }
  if (from.friend_id() != 0) {
    _internal_set_friend_id(from._internal_friend_id());
  }
}

void SendMsgToFriend::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:chatroom.msgpb.SendMsgToFriend)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SendMsgToFriend::CopyFrom(const SendMsgToFriend& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:chatroom.msgpb.SendMsgToFriend)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SendMsgToFriend::IsInitialized() const {
  return true;
}

void SendMsgToFriend::InternalSwap(SendMsgToFriend* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  msg_.Swap(&other->msg_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(SendMsgToFriend, friend_id_)
      + sizeof(SendMsgToFriend::friend_id_)
      - PROTOBUF_FIELD_OFFSET(SendMsgToFriend, user_id_)>(
          reinterpret_cast<char*>(&user_id_),
          reinterpret_cast<char*>(&other->user_id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata SendMsgToFriend::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::chatroom::msgpb::SendMsgToFriend* Arena::CreateMaybeMessage< ::chatroom::msgpb::SendMsgToFriend >(Arena* arena) {
  return Arena::CreateMessageInternal< ::chatroom::msgpb::SendMsgToFriend >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>