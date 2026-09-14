# frozen_string_literal: true

module Jekyll
  module NotesTitleSlug
    module_function

    def front_matter(document)
      source = File.read(document.path)
      match = Document::YAML_FRONT_MATTER_REGEXP.match(source)
      match ? (SafeYAML.load(match[1]) || {}) : {}
    end
  end
end

Jekyll::Hooks.register :site, :post_read do |site|
  notes = site.collections["notes"]
  next unless notes

  notes.docs.each do |document|
    front_matter = Jekyll::NotesTitleSlug.front_matter(document)
    title = front_matter["title"]
    explicit_slug = front_matter["slug"]

    next if title.nil? || title.to_s.strip.empty?
    next unless explicit_slug.nil? || explicit_slug.to_s.strip.empty?

    document.data["slug"] = Jekyll::Utils.slugify(title.to_s)

    # Other plugins may have requested the URL before this hook runs.
    document.remove_instance_variable(:@url) if document.instance_variable_defined?(:@url)
  end
end
