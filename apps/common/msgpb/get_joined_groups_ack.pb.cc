// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: get_joined_groups_ack.proto

#include "get_joined_groups_ack.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_get_5fjoined_5fgroups_5fack_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_GroupInfo_get_5fjoined_5fgroups_5fack_2eproto;
namespace chatroom {
namespace msgpb {
class GroupInfoDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<GroupInfo> _instance;
} _GroupInfo_default_instance_;
class GetJoinedGroupsAckDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<GetJoinedGroupsAck> _instance;
} _GetJoinedGroupsAck_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
static void InitDefaultsscc_info_GetJoinedGroupsAck_get_5fjoined_5fgroups_5fack_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::chatroom::msgpb::_GetJoinedGroupsAck_default_instance_;
    new (ptr) ::chatroom::msgpb::GetJoinedGroupsAck();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::chatroom::msgpb::GetJoinedGroupsAck::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_GetJoinedGroupsAck_get_5fjoined_5fgroups_5fack_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_GetJoinedGroupsAck_get_5fjoined_5fgroups_5fack_2eproto}, {
      &scc_info_GroupInfo_get_5fjoined_5fgroups_5fack_2eproto.base,}};

static void InitDefaultsscc_info_GroupInfo_get_5fjoined_5fgroups_5fack_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::chatroom::msgpb::_GroupInfo_default_instance_;
    new (ptr) ::chatroom::msgpb::GroupInfo();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::chatroom::msgpb::GroupInfo::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_GroupInfo_get_5fjoined_5fgroups_5fack_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_GroupInfo_get_5fjoined_5fgroups_5fack_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_get_5fjoined_5fgroups_5fack_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_get_5fjoined_5fgroups_5fack_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_get_5fjoined_5fgroups_5fack_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_get_5fjoined_5fgroups_5fack_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GroupInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GroupInfo, id_),
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GroupInfo, name_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GetJoinedGroupsAck, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GetJoinedGroupsAck, success_),
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GetJoinedGroupsAck, errmsg_),
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GetJoinedGroupsAck, groups_info_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::chatroom::msgpb::GroupInfo)},
  { 7, -1, sizeof(::chatroom::msgpb::GetJoinedGroupsAck)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::chatroom::msgpb::_GroupInfo_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::chatroom::msgpb::_GetJoinedGroupsAck_default_instance_),
};

const char descriptor_table_protodef_get_5fjoined_5fgroups_5fack_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\033get_joined_groups_ack.proto\022\016chatroom."
  "msgpb\"%\n\tGroupInfo\022\n\n\002id\030\001 \001(\r\022\014\n\004name\030\002"
  " \001(\t\"e\n\022GetJoinedGroupsAck\022\017\n\007success\030\001 "
  "\001(\010\022\016\n\006errmsg\030\002 \001(\t\022.\n\013groups_info\030\003 \003(\013"
  "2\031.chatroom.msgpb.GroupInfob\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_get_5fjoined_5fgroups_5fack_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_get_5fjoined_5fgroups_5fack_2eproto_sccs[2] = {
  &scc_info_GetJoinedGroupsAck_get_5fjoined_5fgroups_5fack_2eproto.base,
  &scc_info_GroupInfo_get_5fjoined_5fgroups_5fack_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_get_5fjoined_5fgroups_5fack_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_get_5fjoined_5fgroups_5fack_2eproto = {
  false, false, descriptor_table_protodef_get_5fjoined_5fgroups_5fack_2eproto, "get_joined_groups_ack.proto", 195,
  &descriptor_table_get_5fjoined_5fgroups_5fack_2eproto_once, descriptor_table_get_5fjoined_5fgroups_5fack_2eproto_sccs, descriptor_table_get_5fjoined_5fgroups_5fack_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_get_5fjoined_5fgroups_5fack_2eproto::offsets,
  file_level_metadata_get_5fjoined_5fgroups_5fack_2eproto, 2, file_level_enum_descriptors_get_5fjoined_5fgroups_5fack_2eproto, file_level_service_descriptors_get_5fjoined_5fgroups_5fack_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_get_5fjoined_5fgroups_5fack_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_get_5fjoined_5fgroups_5fack_2eproto)), true);
namespace chatroom {
namespace msgpb {

// ===================================================================

void GroupInfo::InitAsDefaultInstance() {
}
class GroupInfo::_Internal {
 public:
};

GroupInfo::GroupInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:chatroom.msgpb.GroupInfo)
}
GroupInfo::GroupInfo(const GroupInfo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_name(),
      GetArena());
  }
  id_ = from.id_;
  // @@protoc_insertion_point(copy_constructor:chatroom.msgpb.GroupInfo)
}

void GroupInfo::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_GroupInfo_get_5fjoined_5fgroups_5fack_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  id_ = 0u;
}

GroupInfo::~GroupInfo() {
  // @@protoc_insertion_point(destructor:chatroom.msgpb.GroupInfo)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void GroupInfo::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void GroupInfo::ArenaDtor(void* object) {
  GroupInfo* _this = reinterpret_cast< GroupInfo* >(object);
  (void)_this;
}
void GroupInfo::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void GroupInfo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const GroupInfo& GroupInfo::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_GroupInfo_get_5fjoined_5fgroups_5fack_2eproto.base);
  return *internal_default_instance();
}


void GroupInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:chatroom.msgpb.GroupInfo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  id_ = 0u;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GroupInfo::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // uint32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "chatroom.msgpb.GroupInfo.name"));
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

::PROTOBUF_NAMESPACE_ID::uint8* GroupInfo::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:chatroom.msgpb.GroupInfo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 id = 1;
  if (this->id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_id(), target);
  }

  // string name = 2;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "chatroom.msgpb.GroupInfo.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:chatroom.msgpb.GroupInfo)
  return target;
}

size_t GroupInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:chatroom.msgpb.GroupInfo)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 2;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // uint32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GroupInfo::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:chatroom.msgpb.GroupInfo)
  GOOGLE_DCHECK_NE(&from, this);
  const GroupInfo* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<GroupInfo>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:chatroom.msgpb.GroupInfo)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:chatroom.msgpb.GroupInfo)
    MergeFrom(*source);
  }
}

void GroupInfo::MergeFrom(const GroupInfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:chatroom.msgpb.GroupInfo)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (from.id() != 0) {
    _internal_set_id(from._internal_id());
  }
}

void GroupInfo::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:chatroom.msgpb.GroupInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GroupInfo::CopyFrom(const GroupInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:chatroom.msgpb.GroupInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GroupInfo::IsInitialized() const {
  return true;
}

void GroupInfo::InternalSwap(GroupInfo* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(id_, other->id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata GroupInfo::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void GetJoinedGroupsAck::InitAsDefaultInstance() {
}
class GetJoinedGroupsAck::_Internal {
 public:
};

GetJoinedGroupsAck::GetJoinedGroupsAck(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  groups_info_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:chatroom.msgpb.GetJoinedGroupsAck)
}
GetJoinedGroupsAck::GetJoinedGroupsAck(const GetJoinedGroupsAck& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      groups_info_(from.groups_info_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  errmsg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_errmsg().empty()) {
    errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_errmsg(),
      GetArena());
  }
  success_ = from.success_;
  // @@protoc_insertion_point(copy_constructor:chatroom.msgpb.GetJoinedGroupsAck)
}

void GetJoinedGroupsAck::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_GetJoinedGroupsAck_get_5fjoined_5fgroups_5fack_2eproto.base);
  errmsg_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  success_ = false;
}

GetJoinedGroupsAck::~GetJoinedGroupsAck() {
  // @@protoc_insertion_point(destructor:chatroom.msgpb.GetJoinedGroupsAck)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void GetJoinedGroupsAck::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  errmsg_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void GetJoinedGroupsAck::ArenaDtor(void* object) {
  GetJoinedGroupsAck* _this = reinterpret_cast< GetJoinedGroupsAck* >(object);
  (void)_this;
}
void GetJoinedGroupsAck::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void GetJoinedGroupsAck::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const GetJoinedGroupsAck& GetJoinedGroupsAck::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_GetJoinedGroupsAck_get_5fjoined_5fgroups_5fack_2eproto.base);
  return *internal_default_instance();
}


void GetJoinedGroupsAck::Clear() {
// @@protoc_insertion_point(message_clear_start:chatroom.msgpb.GetJoinedGroupsAck)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  groups_info_.Clear();
  errmsg_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  success_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GetJoinedGroupsAck::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bool success = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          success_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string errmsg = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_errmsg();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "chatroom.msgpb.GetJoinedGroupsAck.errmsg"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .chatroom.msgpb.GroupInfo groups_info = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_groups_info(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* GetJoinedGroupsAck::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:chatroom.msgpb.GetJoinedGroupsAck)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool success = 1;
  if (this->success() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_success(), target);
  }

  // string errmsg = 2;
  if (this->errmsg().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_errmsg().data(), static_cast<int>(this->_internal_errmsg().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "chatroom.msgpb.GetJoinedGroupsAck.errmsg");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_errmsg(), target);
  }

  // repeated .chatroom.msgpb.GroupInfo groups_info = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_groups_info_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, this->_internal_groups_info(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:chatroom.msgpb.GetJoinedGroupsAck)
  return target;
}

size_t GetJoinedGroupsAck::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:chatroom.msgpb.GetJoinedGroupsAck)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .chatroom.msgpb.GroupInfo groups_info = 3;
  total_size += 1UL * this->_internal_groups_info_size();
  for (const auto& msg : this->groups_info_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string errmsg = 2;
  if (this->errmsg().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_errmsg());
  }

  // bool success = 1;
  if (this->success() != 0) {
    total_size += 1 + 1;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GetJoinedGroupsAck::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:chatroom.msgpb.GetJoinedGroupsAck)
  GOOGLE_DCHECK_NE(&from, this);
  const GetJoinedGroupsAck* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<GetJoinedGroupsAck>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:chatroom.msgpb.GetJoinedGroupsAck)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:chatroom.msgpb.GetJoinedGroupsAck)
    MergeFrom(*source);
  }
}

void GetJoinedGroupsAck::MergeFrom(const GetJoinedGroupsAck& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:chatroom.msgpb.GetJoinedGroupsAck)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  groups_info_.MergeFrom(from.groups_info_);
  if (from.errmsg().size() > 0) {
    _internal_set_errmsg(from._internal_errmsg());
  }
  if (from.success() != 0) {
    _internal_set_success(from._internal_success());
  }
}

void GetJoinedGroupsAck::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:chatroom.msgpb.GetJoinedGroupsAck)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetJoinedGroupsAck::CopyFrom(const GetJoinedGroupsAck& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:chatroom.msgpb.GetJoinedGroupsAck)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetJoinedGroupsAck::IsInitialized() const {
  return true;
}

void GetJoinedGroupsAck::InternalSwap(GetJoinedGroupsAck* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  groups_info_.InternalSwap(&other->groups_info_);
  errmsg_.Swap(&other->errmsg_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  swap(success_, other->success_);
}

::PROTOBUF_NAMESPACE_ID::Metadata GetJoinedGroupsAck::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::chatroom::msgpb::GroupInfo* Arena::CreateMaybeMessage< ::chatroom::msgpb::GroupInfo >(Arena* arena) {
  return Arena::CreateMessageInternal< ::chatroom::msgpb::GroupInfo >(arena);
}
template<> PROTOBUF_NOINLINE ::chatroom::msgpb::GetJoinedGroupsAck* Arena::CreateMaybeMessage< ::chatroom::msgpb::GetJoinedGroupsAck >(Arena* arena) {
  return Arena::CreateMessageInternal< ::chatroom::msgpb::GetJoinedGroupsAck >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>